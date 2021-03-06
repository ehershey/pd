//      /adm/daemon/race_d.c
//      the daemon for setting up race info
//      from the Nightmare Mudlib
//      created by Descartes of Borg 10 june 1993
//
//      rewritten completely by Nulvect 2010-07-27

// TODO:
// edit hospitals, replace spell, torpor spell to not use query_limb_info

#include <dirs.h>
#include <race_cl.h>
#include <daemons.h>

// be sure this has a / at the end!
#define RACE_DIR DIR_DB+"/all_races/"

// for generating stat graphs in help files
#define SCALE_LOW 1
#define SCALE_HIGH 5
#define MAX_STARS 17

// all race data in one array of structs
class Race *races;

// for generating stat graphs in help files
static int MinStatCost, MaxStatCost;

void reload_race_configs();
void load_race_configs();
void reload_race(string name);
void parse_race_config(string file);
mapping parse_limb_config(string *data);
void remove_race(string name);
class Race query_race_data(string name);
int is_race(string name);
int query_is_race(string name);
int is_player_race(string race);
int is_monster_race(string race);
string *query_races();
string *query_player_races();
string *query_new_player_races();
string *query_aliases(string race);
varargs int query_weight(string name, int con);
int query_monster_fingers(string race);
int query_fingers(string name);
int query_sight_bonus(string name);
int query_undead(string name);
string *query_genders(string race);
string query_language(string race);
string query_alignment(string race);
string query_class(string race);
string query_subclass(string race);
mapping query_race_limb_data(string name);
mapping query_limb(string limb, string race);
string *query_limbs(string name);
int is_limb(string limb, string race);
int query_is_limb(string limb, string race);
string *query_monster_wielding_limbs(string race);
string *query_wielding_limbs(string name);
mapping query_limb_info(string limb, string race);
int query_max_dam(string limb, string race, int max_hp, int monster);
int query_importance(string limb, string race);
string *query_required_limbs(string what, string race);
string *query_poison_limbs(string race);
string *query_race_stats(string race);
int query_stat_adjustment(string stat, string race);
int query_stat_roll(string stat, string race);
int query_stat_cost(string stat, string race);
string *query_race_skills(string race);
int query_skill_start(string skill, string race);
int query_skill_max(string skill, string race);
int query_skill_cost(string skill, string race);
mapping query_resistances(string race);
mapping query_properties(string race);
int query_healrate(string which, string race);
int query_undead(string race);
int query_rideable(string race);
string query_language(string race);
mapping body(object ob);
mapping monster_body(string race, int maxhp);
mapping do_rolls(string race);
private static void set_help_file(string race, string text);
string query_help_file(string);
private static string help_limbs(string race);
private static string help_resistances(string race);


void create() {
  reload_race_configs();
}


// Configs ------//
void reload_race_configs() {
  races = ({});
  load_race_configs();
}
void load_race_configs() {
  string *dir = get_dir(RACE_DIR);

  MinStatCost = MaxStatCost = 100;

  // load the default race first
  parse_race_config("default");

  foreach (string file in dir) {
    parse_race_config(file);
  }
}
void reload_race(string name) {
  remove_race(name);
  parse_race_config(name);
}
void parse_race_config(string file) {
  string *data;
  class Race r;
  string help;

  if (query_is_race(file)) return;

  if (file_size(RACE_DIR+file) < 1) return;
  data = explode(""+read_file(RACE_DIR+file), "\n");

  r = new(class Race);
  r->name = file;
  r->limbs = ([]);
  r->stats = ([]);
  r->skills = ([]);
  r->resistances = ([]);
  r->properties = ([]);
  r->healrate = ([ ]);
  r->help = ([ "physical" : "", "racial" : ""]);
  r->genders = ({});
  r->aliases = ({});

  // add it to the race list - changes we make later should stick
  races += ({ r });

  // we only default on these seven things to discourage extreme laziness
  if (r->name != "default") {
    r->sight = query_sight_bonus("default");
    r->size = query_weight("default");
    r->fingers = query_fingers("default");
    r->language = query_language("default");
    r->undead = query_undead("default");
    r->rideable = query_rideable("default");
    r->alignment = query_alignment("default");
    r->genders = query_genders("default");
  }

  foreach (string line in data) {
    string keyword, setting;
    string parent;
    string *exp;
    int sep;

    if (line[0..0] == "#") continue;
    if (line[<1..<1] == "\r") line = line[0..<2];
    if (!strlen(line)) continue;

    sep = strsrch(line, " ");
    if (sep == -1) continue;

    keyword = line[0 .. sep-1];
    setting = line[sep+1 .. <1];
    exp = explode(setting, ":");

    if (help) {
      switch (keyword) {
      case "end":
        help = 0;
        break;
      default:
        r->help[help] += line + " ";
      }
      continue; // the foreach loop
    }

    switch (keyword) {

    case "player":
      r->player = to_int(setting);
      break;

    case "newplayer":
      r->newplayer = to_int(setting);
      break;

    case "sight":
      r->sight = to_int(setting);
      break;

    case "size":
    case "weight":
      r->size = to_int(setting);
      break;

    case "fingers":
      r->fingers = to_int(setting);
      break;

    case "undead":
      r->undead = to_int(setting);
      break;

    case "rideable":
      r->rideable = to_int(setting);
      break;

    case "alignment":
      r->alignment = ""+setting;
      break;

    case "language":
      r->language = ""+setting;
      break;

    case "class":
      r->myclass = exp[0];
      r->mysub = exp[1];
      break;

    case "resistance":
      r->resistances[exp[0]] = to_int(exp[1]);
      break;

    case "property":
      r->properties[exp[0]] = to_int(exp[1]);
      break;

    case "healrate":
      r->healrate[exp[0]] = to_int(exp[1]);
      break;

    case "stat":
      r->stats[exp[0]] = ([
       "roll" : to_int(exp[1]),
       "cost" : to_int(exp[2]),
      ]);
      if (r->player) {
        if (r->stats[exp[0]]["cost"] > MaxStatCost)
          MaxStatCost = r->stats[exp[0]]["cost"];
        if (r->stats[exp[0]]["cost"] < MinStatCost)
          MinStatCost = r->stats[exp[0]]["cost"];
      }
      break;

    case "skill":
      r->skills[exp[0]] = ([
       "start" : to_int(exp[1]),
       "max" : to_int(exp[2]),
       "cost" : to_int(exp[3]),
      ]);
      break;

    case "limb":
      r->limbs[exp[0]] = parse_limb_config(exp);
      parent = r->limbs[exp[0]]["parent"];
      if (!nullp(r->limbs[parent]))
        r->limbs[parent]["children"] += ({ exp[0] });
      break;

    case "gender":
    case "genders":
      r->genders = exp;
      break;

    case "alias":
    case "aliases":
      r->aliases += exp;
      break;

    case "help":
      help = ""+setting;
      r->help[help] = "";
      break;

    case "body":
      // if depending on another race, make sure it's loaded first
      if (!query_is_race(setting) && setting != r->name)
        parse_race_config(setting);
      // double check that it succeeded loading
      if (query_is_race(setting))
        r->limbs = query_race_limb_data(setting);
      break;

    case "delete":
      foreach (string l in exp)
        map_delete(r->limbs, l);
      break;
    }
  }

}

mapping parse_limb_config(string *data) {
  int fatal = 0, wield = 0, poison = 0, ac = 0;
  string required="";
  string *tmp;
  mapping ret;

  if (sizeof(data) > 3) {
    tmp = explode(data[3], ",");
    foreach (string limbopt in tmp) {
      switch (limbopt) {
      case "wield": wield=1; break;
      case "fatal": fatal=1; break;
      case "poison": poison=1; break;
      default:
        if (sscanf(limbopt, "ac %d", ac) == 1)
          break;
        else
          // fall through
          ;
      case "walk":
      case "fly":
      case "bite":
        // this is the default for any limb flag not recognized
        required += limbopt + ",";
      }
    }
  }

  ret = ([
   "importance" : to_int(data[1]),
   "parent" : ""+data[2],
   "children" : ({}),
   "fatal" : fatal,
   "wield" : wield,
   "poison" : poison,
   "ac" : ac,
   "required" : required,
  ]);

  return ret;
}

void remove_race(string name) {
  class Race *search = filter(races, (: $1->name == $2 :), name);
  if (sizeof(search))
    races -= ({ search[0] });
}

// Race queries -//

class Race query_race_data(string name) {
  class Race ret;
  class Race *search;
  if (!name || !strlen(name))
    name = "default";
  // make a list of all races with this name,
  // plus all races with this as an alias
  search = filter(races,
   (:
    $1->name == $2 || member_array($2, $1->aliases) != -1
   :),
   name
  );
  // above should only result in one entry max
  if (sizeof(search))
    return copy(search[0]);
  return 0;
}

int is_race(string name) { return query_is_race(name); }
int query_is_race(string name) { return (query_race_data(name) ? 1 : 0); }

int is_player_race(string race) {
  return member_array(race, query_player_races()) != -1;
}
int is_monster_race(string race) { return query_is_race(race); }

string *query_races() { return map(races, (: $1->name :) ); }
string *query_player_races() {
  return map(
   // first filter it down to only player races
   filter(races, (: $1->player == 1 :)),
   // then return their names
   (: $1->name :)
  );
}

string *query_new_player_races() {
  return map(
   // first filter to new player races
   filter(races, (: $1->player == 1 && $1->newplayer == 1 :)),
   // then return their names
   (: $1->name :)
  );
}

string *query_aliases(string race) {
  class Race r = query_race_data(race);
  if (r)
    return copy(r->aliases);
  return ({});
}

// Various ------//

// weight, sight, fingers, undead, alignment, language, genders, and rideable
// will all be copied from default info if not given

varargs int query_weight(string name, int con) {
  class Race r = query_race_data(name) || query_race_data("default");
  int ret;

  ret = r->size;

  // this was the formula in the old race_d, seems extreme though
  // each point of con == 100 weight
  // unused at this time
  if (con)
    ret += (con-10)*100;

  return ret;
}

int query_monster_fingers(string race) {
  return query_fingers(race);
}
int query_fingers(string name) {
  class Race r = query_race_data(name) || query_race_data("default");
  return r->fingers;
}

int query_sight_bonus(string name) {
  class Race r = query_race_data(name) || query_race_data("default");
  return r->sight;
}

int query_undead(string name) {
  class Race r = query_race_data(name) || query_race_data("default");
  return r->undead;
}

string *query_genders(string race) {
  class Race r = query_race_data(race) || query_race_data("default");
  return r->genders;
}

string query_language(string race) {
  class Race r = query_race_data(race) || query_race_data("default");
  return r->language;
}

string query_alignment(string race) {
  class Race r = query_race_data(race) || query_race_data("default");
  return r->alignment;
}

int query_rideable(string race) {
  class Race r = query_race_data(race) || query_race_data("default");
  return r->rideable;
}

mapping query_properties(string race) {
  class Race r = query_race_data(race) || query_race_data("default");
  return copy(r->properties);
}

int query_healrate(string which, string race) {
  class Race r = query_race_data(race);
  return r->healrate[which];
}

string query_class(string race) {
  class Race r = query_race_data(race);
  if (r)
    return r->myclass;
  return 0;
}

string query_subclass(string race) {
  class Race r = query_race_data(race);
  if (r)
    return r->mysub;
  return 0;
}

// Limbs --------//

mapping query_race_limb_data(string name) {
  class Race r = query_race_data(name) || query_race_data("default");
  return copy(r->limbs);
}

mapping query_limb(string limb, string race) {
  mapping limbs = query_race_limb_data(race);
  if (query_is_limb(limb, race))
    return copy(limbs[limb]);
  return ([]);
}

string *query_limbs(string name) { return keys(query_race_limb_data(name)); }

int is_limb(string limb, string race) { return query_is_limb(limb, race); }
int query_is_limb(string limb, string race) {
  return member_array(limb, query_limbs(race)) != -1;
}

string *query_monster_wielding_limbs(string race) {
  return query_wielding_limbs(race);
}
string *query_wielding_limbs(string name) {
  mapping limbdata = query_race_limb_data(name);
  limbdata = filter(limbdata, (: $2["wield"] == 1 :) );
  return keys(limbdata);
}

// exists purely for backwards compatibility
mapping query_limb_info(string limb, string race) {
  mapping limbs = query_race_limb_data(race);
  mapping tmp;
  if (nullp(limbs[limb]))
    return ([]);
  tmp = ([
   "max" : limbs[limb]["importance"],
  ]);
  if (limbs[limb]["fatal"])
    tmp["ref"] = "FATAL";
  else if (sizeof(limbs[limb]["children"]))
    tmp["ref"] = limbs[limb]["children"][0];
  else
    tmp["ref"] = "";
  if (limbs[limb]["parent"]) {
    if (limbs[limb]["parent"] == "torso")
      tmp["attach"] = "0";
    else
      tmp["attach"] = limbs[limb]["parent"];
  }
  else
    tmp["attach"] = "0";
  return tmp;
}

// notice the different formulas
// h / (i * 5) for mobs
// (h / i) * 5 for players
// thus, players have much higher max limb damage
// this may be changed in the future
int query_max_dam(string limb, string race, int max_hp, int monster) {
  int im = query_importance(limb, race);
  if (monster)
    return max_hp / (im * 5);
  else
    return (max_hp / im) * 5;
}

int query_importance(string limb, string race) {
  mapping limbs = query_race_limb_data(race);
  if (nullp(limbs[limb]))
    return 1;
  return limbs[limb]["importance"];
}

string *query_required_limbs(string what, string race) {
  mapping limbs = query_race_limb_data(race);
  limbs = filter(limbs,
   (:
    member_array($3, explode($2["required"], ",")) != -1
   :),
   what
  );
  return keys(limbs);
}

string *query_poison_limbs(string race) {
  mapping limbs = query_race_limb_data(race);
  limbs = filter(limbs,
   (: $2["poison"] == 1 :),
  );
  return keys(limbs);
}

// Stats --------//

string *query_race_stats(string race) {
  class Race r = query_race_data(race) || query_race_data("default");
  if (r)
    return keys(r->stats);
  return ({});
}

int query_stat_adjustment(string stat, string race) {
  return query_stat_roll(stat, race);
}
int query_stat_roll(string stat, string race) {
  class Race r = query_race_data(race) || query_race_data("default");
  return r->stats[stat]["roll"];
}

int query_stat_cost(string stat, string race) {
  class Race r = query_race_data(race) || query_race_data("default");
  return r->stats[stat]["cost"];
}

// Skills -------//

string *query_race_skills(string race) {
  class Race r = query_race_data(race);
  if (r)
    return keys(r->skills);
  return ({});
}

int query_skill_start(string skill, string race) {
  class Race r = query_race_data(race);
  if (r && !nullp(r->skills[skill]))
    return r->skills[skill]["start"];
  return 0;
}

int query_skill_max(string skill, string race) {
  class Race r = query_race_data(race);
  if (r && !nullp(r->skills[skill]))
    return r->skills[skill]["max"];
  return 0;
}

int query_skill_cost(string skill, string race) {
  class Race r = query_race_data(race);
  if (r && !nullp(r->skills[skill]))
    return r->skills[skill]["cost"];
  return 0;
}

// Resistances ---//

mapping query_resistances(string race) {
  class Race r = query_race_data(race);
  if (r)
    return copy(r->resistances);
  return ([]);
}

// Generators ----//

mapping body(object ob) {
  string race;
  mapping limbs;
  int max_hp;
  int monster = ob->is_monster();

  if (monster) {
    race = ob->query_body_type();
    if (!race)
      race = ob->query_race();
  }
  else
    race = ob->query_race();

  limbs = query_race_limb_data(race);
  max_hp = ob->query_max_hp();

  foreach (string limb, mapping data in limbs) {
    int max;
    string limbref;

    max = query_max_dam(limb, race, max_hp, monster);

    if (data["fatal"] == 1)
      limbref = "FATAL";
    else if (sizeof(data["children"]))
      limbref = data["children"][0];
    else
      limbref = "";

    // change to the stuff the current body.c expects to be there
    // was going to leave the other stuff in, but it's mostly things that
    // are universal to the race so don't need to be in every player
    limbs[limb] = ([
     "limb_ref" : limbref,
     "max_dam" : max,
     "damage" : 0,
     "ac" : data["ac"],
     "status" : 0,
    ]);
    if (data["wield"] == 1)
      limbs[limb]["wieldable"] = 1;
  }

  return limbs;
}

// backwards compat only
mapping monster_body(string race, int maxhp) {
  if (previous_object() && previous_object()->is_living())
    return body(previous_object());
  return ([]);
}

mapping do_rolls(string race) {
  class Race r;
  mapping rolls;

  r = query_race_data(race) || query_race_data("default");

  rolls = map(r->stats, function(string stat, mapping data) {
     int value = 7 + random(10) + data["roll"];
     if (value < 2) value = 2;
     if (value > 23) value = 23;
     return value;
   } );

  return rolls;
}

private static void set_help_file(string race, string text) {
  class Race *r;
  r = filter(races, (: $1->name == $2 :), race);
  if (sizeof(r)) {
    r[0]->help["generated"] = text;
  }
}

void show_help(string race) {
  if (this_player())
    message("help",
     query_help_file(race),
     this_player()
    );
}

// create part of a help file to display
string query_help_file(string race) {
  string str, con, dex, cha, intel, wis;
  string sight, quest, limbdata, resist;
  int arms, legs;
  string out;
  function stat_stars;
  class Race r;

  if (!is_player_race(race))
    return "";

  r = query_race_data(race);
  if (r && r->help["generated"] && strlen(r->help["generated"]))
    return r->help["generated"];

  if (member_array(race, query_new_player_races()) == -1)
    quest = "Yes";
  else
    quest = "No";

  sight = repeat_string("*", query_sight_bonus(race)+3);

  arms = sizeof(regexp(query_limbs(race), "arm"));
  legs = sizeof(regexp(query_limbs(race), "leg"));

  limbdata = help_limbs(race);

  resist = help_resistances(race);

  // this part generates the stat cost graphs
  stat_stars = function(int cost) {
    int stars, range;
    string tmp, out;
    stars = MAX_STARS / 2 + 1;
    range = 100 - cost;
    if (range > 0)
      stars += ((range / SCALE_LOW)+1)/2;
    if (range < 0)
      stars += ((range / SCALE_HIGH)-1)/2;
    if (stars > MAX_STARS)
      stars = MAX_STARS;
    if (stars < 1)
      stars = 1;
    tmp = repeat_string("*", stars);
    out = "";
    for (int i = 0; i < strlen(tmp); i++) {
      out += tmp[i..i];
      switch (i) {
        /*
        case 2: case 5: case 7:
        case 8:
        case 10: case 13:
        */
      case 2: case 5: case 8:
      case 11: case 14:
        out += " ";
      default:
      }
    }
    return out;
  };

  str = evaluate(stat_stars, query_stat_cost("strength", race));
  con = evaluate(stat_stars, query_stat_cost("constitution", race));
  dex = evaluate(stat_stars, query_stat_cost("dexterity", race));
  cha = evaluate(stat_stars, query_stat_cost("charisma", race));
  intel = evaluate(stat_stars, query_stat_cost("intelligence", race));
  wis = evaluate(stat_stars, query_stat_cost("wisdom", race));
  // end of stat cost graphs

  // now we put it all together
  out = header_line(capitalize(race))+"\n\n";

  out += sprintf("%%^BOLD%%^%%^BLUE%%^%-15s %%^CYAN%%^%-*s          %%^BLUE%%^%s %%^RESET%%^%d\n",
   "Strength:", MAX_STARS+5, str, "Number of arms:", arms
  );
  out += sprintf("%%^BOLD%%^%%^BLUE%%^%-15s %%^CYAN%%^%-*s          %%^BLUE%%^%s %%^RESET%%^%d\n",
   "Constitution:", MAX_STARS+5, con, "Number of legs:", legs
  );
  out += sprintf("%%^BOLD%%^%%^BLUE%%^%-15s %%^CYAN%%^%-*s          %%^BLUE%%^%s %%^RESET%%^%d\n",
   "Dexterity:", MAX_STARS+5, dex, "Number of fingers per hand:", query_fingers(race)
  );
  out += sprintf("%%^BOLD%%^%%^BLUE%%^%-15s %%^CYAN%%^%-*s          %%^BLUE%%^%s %%^CYAN%%^%s\n",
   "Charisma:", MAX_STARS+5, cha, "Night vision:", sight
  );
  out += sprintf("%%^BOLD%%^%%^BLUE%%^%-15s %%^CYAN%%^%-*s          %%^BLUE%%^%s %%^MAGENTA%%^%s\n",
   "Intelligence:", MAX_STARS+5, intel, "Quest race:", quest
  );
  out += sprintf("%%^BOLD%%^%%^BLUE%%^%-15s %%^CYAN%%^%-*s          %%^BLUE%%^%s %%^RESET%%^%s\n",
   "Wisdom:", MAX_STARS+5, wis, "Language:", capitalize(query_language(race))
  );

  out += header_line() + "\n";

  out += "%^BOLD%^%^BLUE%^Limbs:%^RESET%^\n";
  out += terminal_colour(limbdata, TERMINAL_D->query_term_info("wrap"), 75, 0);
  out += "\n";

  out += header_line() + "\n";

  out += "%^BOLD%^%^MAGENTA%^Physical description:%^RESET%^\n";
  out += terminal_colour(r->help["physical"], TERMINAL_D->query_term_info("wrap"), 75, 0);
  out += "\n";

  out += header_line() + "\n";

  out += "%^BOLD%^%^MAGENTA%^Racial characteristics:%^RESET%^\n";
  out += terminal_colour(r->help["racial"], TERMINAL_D->query_term_info("wrap"), 75, 0);
  out += "\n";

  out += header_line()+"\n";

  out += "%^BOLD%^%^CYAN%^Damage resistances:%^RESET%^\n";
  out += terminal_colour(resist, TERMINAL_D->query_term_info("wrap"), 75, 0);
  out += "\n";

  out += header_line()+"\n";

  set_help_file(race, out);

  return out;
}

// this section is really complicated,
// it generates the "Imps have wings and a tail." part of the help file
private static string help_limbs(string race) {
  string *limbs, *tmplimbs;
  string limbdata;
  int arms, legs, tmp;

  limbs = query_limbs(race);
  arms = sizeof(regexp(limbs, "arm"));
  legs = sizeof(regexp(limbs, "leg"));

  tmplimbs = limbs - query_limbs("human");
  tmp = sizeof(limbs & query_limbs("human"));
  if (tmp == sizeof(limbs))
    limbdata = "Standard humanoid";
  else {
    tmplimbs = limbs - ({ "torso", "head" });
    if (arms == 2) {
      tmplimbs = tmplimbs - regexp(tmplimbs, "arm|hand");
    }
    if (legs == 2) {
      tmplimbs = tmplimbs - regexp(tmplimbs, "leg|foot");
    }
    tmplimbs = sort_array(tmplimbs, function(string l1, string l2, string race) {
       int il1 = query_importance(l1, race);
       int il2 = query_importance(l2, race);
       if (il1 > il2) return -1;
       if (il2 > il1) return 1;
       return 0;
     }, race);
    tmplimbs = map(tmplimbs, function(string limb) {
       limb = replace_string(limb, "left ", "");
       limb = replace_string(limb, "right ", "");
       limb = replace_string(limb, "first ", "");
       limb = replace_string(limb, "second ", "");
       limb = replace_string(limb, "third ", "");
       limb = replace_string(limb, "fourth ", "");
       limb = replace_string(limb, "fore ", "");
       limb = replace_string(limb, "fore", "");
       limb = replace_string(limb, "front ", "");
       limb = replace_string(limb, "rear ", "");
       if (limb[<1..<1] != "s")
         limb = indefinite_article(limb);
       return limb;
     } );
    tmplimbs = unique_array(tmplimbs, (: $1 :) );
    tmplimbs = map(tmplimbs, (: consolidate_string($1) :) );
    tmplimbs = map(tmplimbs, (: $1[0] :) );
    tmplimbs = map(tmplimbs, function (string limbword) {
       int pos = strsrch(limbword, " ");
       string first;
       if (pos != -1) {
         first = limbword[0..pos-1];
         if (first == "two")
           return limbword[pos+1..<1];
       }
       return limbword;
     } );
    limbdata = capitalize(pluralize(race))+" have "+list(tmplimbs);
  }
  limbdata += ".";

  return limbdata;
}

// generates "Raknids are strong against impact damage, they are very weak against pierce damage."
private static string help_resistances(string race) {
  string resist = "";
  mapping strong, weak;

  strong = ([
   "" : ({}),
   "slightly" : ({}),
   "very" : ({}),
   "extremely" : ({}),
   "incredibly" : ({}),
  ]);
  weak = ([
   "" : ({}),
   "slightly" : ({}),
   "very" : ({}),
   "extremely" : ({}),
   "incredibly" : ({}),
  ]);
  foreach (string type, int amt in query_resistances(race)) {
    type = lower_case(type[7..<1]);
    switch (amt) {
    case 0..74:
      strong["incredibly"] += ({ type });
      break;
    case 75..84:
      strong["extremely"] += ({ type });
      break;
    case 85..89:
      strong["very"] += ({ type });
      break;
    case 90..94:
      strong[""] += ({ type });
      break;
    case 95..99:
      strong["slightly"] += ({ type });
      break;
    case 100: break;
    case 101..105:
      weak["slightly"] += ({ type });
      break;
    case 106..110:
      weak[""] += ({ type });
      break;
    case 111..115:
      weak["very"] += ({ type });
      break;
    case 116..125:
      weak["extremely"] += ({ type });
      break;
    case 126..200:
      weak["incredibly"] += ({ type });
      break;
    }
  }

  resist = capitalize(pluralize(race))+" ";
  if (!sizeof(query_resistances(race)))
    resist += "have no innate resistances.";
  else {
    strong = filter(strong, (: sizeof($2) :) );
    weak = filter(weak, (: sizeof($2) :) );
    strong = map(strong, (:
      (strlen($1) ? $1 + " " : "") + "resistant to "+list($2) + " damage"
     :) );
    weak = map(weak, (:
      (strlen($1) ? $1 + " " : "") + "weak against "+list($2)+ " damage"
     :) );
    resist += "are ";
    if (sizeof(strong)) {
      resist += implode(values(strong), ", ") + ".";
      if (sizeof(weak))
        resist += "\nThey are "+implode(values(weak), ", ") + ".";
    }
    else if (sizeof(weak))
      resist += implode(values(weak), ", ") + ".";
  }

  if (query_undead(race))
    resist = capitalize(pluralize(race))+" are undead.\n"+resist;

  return resist;
}

