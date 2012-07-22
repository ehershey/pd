/*
 * this daemon holds functions and costs for advancing levels,
 * training skills, and improving stats
 * it also contains query_exp_for_kill which applies exp bonuses and penalties
 *
 * rewritten by Nulvect 2009-12-09
 */
#include <std.h>
#include <daemons.h>

inherit DAEMON;

// for CLASS_STAT_COST
#include <stats.h>

// function prototypes
int query_stat_mod(string cl, string subcl, string race, string stat);
int query_class_stat_mod(string cl, string subcl, string stat);
int query_race_stat_mod(string race, string stat);
int apply_race_modifier(string race, string stat, int cost);
void add_skill_points(object tp, string skill, int amount);
// ---

// configuration variables

// 100% of normal exp, this is for having events that give double exp and such
int GLOBAL_EXP_BONUS_PERC = 100;

int MIN_EXP = 100;
int NORMAL_EXP = 1000;
int NORMAL_EXP_LEVEL = 20;
int BONUS_LEVEL = 50;
int MIN_SKILLS_PER_LEVEL = 15;
string RACE_COST_DIR = "/adm/db/races/cost/";
// ---


void create() {
  // needed for /adm file access:
  seteuid(getuid());
}

int query_level_cost(int newlevel) {
  return newlevel * newlevel * newlevel * 63;
}

int query_skill_cost(string theclass, string subclass, int level, string skill) {
  // too many skill costs to put them all in this daemon,
  // look in /adm/include/skills.h for the listing of maxes and costs
  return SKILLS_D->training_formula(theclass, subclass, level, skill);
}

int query_stat_cost(string cl, string subcl, string race, string stat, int statlevel) {
  int ret, perc;
  float tmp;

  perc = query_stat_mod(cl, subcl, race, stat);

  // must use a float here to avoid buffer overflow
  // this use to be "(statlevel*statlevel*1000)*perc/100"
  // simplified to statlevel*statlevel*10*perc
  tmp = to_float(statlevel) * statlevel * 10 * perc;
  ret = to_int(tmp);

  if (ret < 1)
    ret = 2147483647;
  if (ret < 1000)
    ret = 1000;

  return ret;
}

int query_player_stat_mod(object tp, string stat) {

  return query_stat_mod(tp->query_class(), tp->query_subclass(), tp->query_race(), stat);
}

int query_stat_mod(string cl, string subcl, string race, string stat) {
  int classmod;
  int racemod;
  int ret;

  classmod = query_class_stat_mod(cl, subcl, stat);
  racemod = query_race_stat_mod(race, stat);

  ret = racemod * classmod / 100;

  return ret;
}

int query_class_stat_mod(string cl, string subcl, string stat) {
  int perc;
  mapping percentages;

  percentages = CLASS_STAT_COST[subcl];
  if (!percentages || !percentages[stat])
    percentages = CLASS_STAT_COST[cl];
  if (!percentages || !percentages[stat])
    perc = 100;
  else
    perc = percentages[stat];

  return perc;
}

int query_race_stat_mod(string race, string stat) {
  string filename, fileread, sign;
  string *lines;
  int perc = 0;
 
  // this is seriously stupid, the race daemon should cache this data
  // so we don't have to do disk access everytime someone types "cost"

  filename = RACE_COST_DIR + race + "_stats";
  fileread = read_file(filename);
  if (fileread)
    lines = explode(fileread, "\n");

  // don't need to explicitly check if (!sizeof(lines)), the for loop below
  //   will do this automatically
  // sizeof() is considered a constant in LPC

  for (int i = 0; i < sizeof(lines); i++) {
    if (!lines[i] || lines[i] == "" || lines[i][0] == '#')
      continue;

    // strength;+5%   more expensive
    // wisdom;-10%    less expensive
    // etc
    if (sscanf(lines[i], stat+";%s%d%%", sign, perc) == 2) {

      switch (sign) {
        case "+":
          // note the difference in how + and - costs are applied!!
          perc = perc*7/2;
        break;
        
        case "-":
          perc = -1*(perc/2);
        break;
      }

      break; // out of for loop
    }
  }

  perc = 100 + perc;
   
  return perc;
}

// this needs to be a separate function so the old get_race_change func works
int apply_race_modifier(string race, string stat, int cost) {
  int perc = query_race_stat_mod(race, stat);
  cost = cost * perc / 100;
  return cost;
}

int query_exp_for_level(int level) {
  int exp;

  if (level < NORMAL_EXP_LEVEL) {
    int exprange = NORMAL_EXP - MIN_EXP;
    exp = level * (MIN_EXP + ( exprange * level / NORMAL_EXP_LEVEL ));
  }
  else {
    exp = level * NORMAL_EXP;
  }

  return exp;
}

int query_exp_for_kill(object killer, object victim) {
  int kl, vl, exp, test;

  if (!killer || !victim) return 0;
  if (!killer->is_living() || !victim->is_living()) return 0;

  kl = killer->query_level();
  vl = victim->query_level();

  if (!kl || !vl) return 0;

  if (victim->is_player())
    exp = query_exp_for_level(vl);
  else
    exp = victim->query_exp();

  if (!exp)
    return 0;

  // yes, killer level - only apply exp cuts and bonuses to hm+
  if (kl >= NORMAL_EXP_LEVEL) {

    // bonus exp for killing things more than 25% of your level
    // up to 150% (1.5x) exp bonus
    if (vl > kl*125/100) {
      int top = kl * 150 / 100;
      int bottom = kl * 125 / 100;
      int diff = (top - bottom) * 2;
      int checklevel = (vl > top ? top : vl);
      int per = 100 + ( (checklevel - bottom) * 100 / diff);
      test = exp * per / 100;
    }
    // and/or:
    // auto exp bonus for anything over a certain level
    if (vl > BONUS_LEVEL)
      exp = exp + (vl - BONUS_LEVEL)*1000;

    // apply the better bonus, but not both
    if (test > exp)
      exp = test;

    // penalty to exp for killing things that are under 25% of your level
    // under 50% == 0 exp
    // even the bonus portion of exp will be penalized
    if (vl < kl*75/100) {
      int top = kl * 75 / 100;
      int bottom = kl * 50 / 100;
      int diff = (top - bottom) * 2;
      int per = 100 - ( (top - vl) * 100 / diff);
      if (vl < kl*50/100)
        exp = 0;
      else
        exp = exp * per / 100;
    }

  }

  exp = exp * GLOBAL_EXP_BONUS_PERC / 100;

  return exp;
}

// verb functions below are called by /std/room/hall.c
// (and the wanderer advance ability)
// we want to do all the checks in this daemon though,
// so we'll print our own messages and such
void advance_level(object tp) {
  int lev, newlev, exp;
  int total, cost;
  string rank, race;

  lev = tp->query_level();
  exp = tp->query_exp();
  newlev = lev+1;
  cost = query_level_cost(newlev);
  race = tp->query_race();

  if (cost > exp) {
    message("info", "You are not experienced enough to advance to the next level.", tp);
    return;
  }

  foreach (string sk, mapping info in tp->query_skills())
    total += info["level"];

  if (total < lev*MIN_SKILLS_PER_LEVEL) {
    message("info", "You need to train your skills before leveling.", tp);
    return; 
  }

  tp->add_exp(-cost);
  tp->set_level(newlev);

  switch (newlev) {
    case 100:
      switch (tp->query_gender()) {
        case "female":
          rank = "Heroine";
        break;
        default:
          rank = "Hero";
      }
      switch (race) {
        case "demon":
        case "lich":
          rank = "Anti-"+rank;
        break;
        default: //no prefix for others
      }
      message("info", "You have achieved the glorious power of the "+rank+".", tp);
      log_file("legend", tp->query_cap_name()+" became "+
        indefinite_article(rank)+":"+ctime(time())+"\n");
    break;

    case 20:
      if (!wizardp(tp))
        tp->set_position("high mortal");
      tp->add_search_path(DIR_HM_CMDS);
      message("info", "You have achieved the rank of High Mortal.", tp);
      log_file("high_mortal", tp->query_name()+" became a high mortal: "+ctime(time())+"\n");
    break;
  }

  tp->register_channels();
  tp->fix_vital_bonus(newlev);
  message("info", "You advance to level "+newlev+".", tp);
}

void train_skill(object tp, string skill, int exp) {
  int max, start;

  if (!tp->skill_exists(skill)) {
    message("info", "You do not have a skill by that name.", tp);
    return;
  }

  if (exp < 1) {
    message("info", "You cannot train that amount.", tp);
    return;
  }

  if (exp > tp->query_exp()) {
    message("info", "You do not have the experience to train that much.", tp);
    return;
  }

  max = tp->query_level() * tp->query_max_skill(skill) / 2;
  start = tp->query_base_skill(skill);

  if (start >= max) {
    message("info", "You must advance your level to train more in that skill.", tp);
    return;
  }

  add_skill_points(tp, skill, exp);
  tp->add_exp(-exp);

  if (tp->query_base_skill(skill) > start) {
    if (tp->getenv("SKILL_SHOW") == "1")
      message("info", "%^YELLOW%^You feel more skilled in the art of "+skill+".%^RESET%^\n", tp);
    log_file("skills", tp->query_name()+" advanced "+
      skill+" from "+start+" to "+tp->query_skill(skill)+
      " ("+ctime(time())+")\n");
  }

  message("info", "You train in the skill of "+skill+".", tp);
}

// fix this so if you train attack 5000000 and only need 5000 more exp it won't use it all
// make it so spending 1-3 exp isn't wasted
void add_skill_points(object tp, string skill, int amount) {
  int pts, max, lvl, pts_needed, trained;
  string cl, subcl;

  if (!tp || !tp->skill_exists(skill) || amount < 1)
    return;
  
  amount /= 4;

  cl = tp->query_class();
  subcl = tp->query_subclass();
  pts = tp->query_skill_points(skill);
  lvl = tp->query_skill(skill);

  pts += amount;
  trained = amount;

  max = tp->query_max_skill(skill) * tp->query_level() / 2;

  while( pts > (pts_needed = query_skill_cost(cl, subcl, lvl, skill)) ) {
    pts -= pts_needed;
    if (trained != pts)
      trained += pts_needed;
    if (max > lvl)
      lvl++;
    else
      break;
  }

  // this function does not exist yet
  tp->set_skill_points(skill, pts);

  tp->set_skill(skill, lvl);
}

void improve_stat(object tp, string stat) {
  string *primary;
  string adj;
  int cost, level, newlevel, importance;

  if (!tp || !stat || member_array(stat, tp->query_all_stats()) == -1)
    return;

  level = tp->query_base_stats(stat);
  newlevel = level+1;

  cost = query_stat_cost(tp->query_class(), tp->query_subclass(),
                         tp->query_race(), stat, newlevel);

  if (tp->query_exp() < cost) {
    message("info", "You are not experienced enough to improve yourself in that way.", tp);
    return;
  }

  tp->set_stats(stat, newlevel);
  tp->add_exp(-cost);

  switch (stat) {
    case "strength":
      adj = "stronger";
    break;
    case "dexterity":
      adj = "more nimble";
    break;
    case "constitution":
      adj = "sturdier";
    break;
    case "charisma":
      adj = "more attractive";
    break;
    case "intelligence":
      adj = "more intelligent";
    break;
    case "wisdom":
      adj = "wiser";
    break;
  }

  message("my_action", "You look "+adj+".", tp);
  message("other_action", tp->query_cap_name()+" looks much "+adj+".",
    environment(tp), tp);
}

void roll_stats(object tp) {
  string race;
  mapping stats;

  if (!tp) return;

  race = tp->query_race() || "human";
  stats = RACE_D->do_rolls(race);
  foreach (string stat, int x in stats)
    tp->set_stats(stat, x);

  message("info", "You roll your stats.", tp);
  tp->force_me("stats");
}

// --- backwards-compatibility functions ---
int get_exp(int lev) {
  return query_level_cost(lev);
}
int get_stat_cost(int x, int lev, string stat) {
  object tp = this_player();
  if (tp)
    return query_stat_cost(tp->query_class(), tp->query_subclass(),
                           tp->query_race(), stat, lev);
  return query_stat_cost("child", "none", "human", stat, lev);
}
int get_race_change(string race, string stat, int cost) {
  return apply_race_modifier(race, stat, cost);
}
int train_player(object tp, string skill, int exp) {
  train_skill(tp, skill, exp);
  return 1;
}
int advance() {
  if (this_player())
    advance_level(this_player());
  return 1;
}
// ---

// there is probably a better place for this
string get_new_title(object tp) {
  string title;
  string sub = tp->query_subclass();

  switch (sub) {
    case "none":
      title = "Newbie $N the ";
      switch (tp->query_gender()) {
        case "male":
          title += "boy";
        break;
        case "female":
          title += "girl";
        break;
        default:
          title += "neuter";
      }
    break;

    default:
      title = "$N the novice "+sub;
  }

  return title;
}

// why is this here??
void log_death(string str) { log_file("kills", str); }

