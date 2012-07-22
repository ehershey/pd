///      /std/living/combat.c
//      from the Nightmare mudlib
//      code for combat
//      based upon the LOS combat by Buddha@TMI
//      created by Descartes of Borg september 1992

#include <std.h>
#include <party.h>
#include <daemons.h>
#include <council.h>
#include <balance.h>
#include <function.h>

#define MAX_MELEE_WC        15
#define MAX_ATTACK_BONUS    3
#define MAX_NUM_ATTACKS     6
// Note: fighters get +2 bonus to MAX_NUM_ATTACKS
//Changed from 19 to ban PK temporarily
#define NEWBIE_LEVEL 19
#define KILL_RANGE 5
#define DEFAULT_PARALYZE_MESSAGE "You are stiff as stone."
//Normal Damage Message Color
#define ATTCL "%^RED%^"
//Missed Attack Message Color
#define MISSCL "%^GREEN%^"
//High Damage Message Color
#define HIATTCL "%^BOLD%^%^CYAN%^"
//inherit BODY;
inherit "/std/living/body";
inherit SKILLS;

static int paralyzed, magic_round;
static int hunting;
int wimpy;
private string wimpydir;
private static object *attackers;
object last_attacker;
static string last_atk_path;
private static int any_attack;
private static int casting;
private static object *hunters;
private static mapping magic_protection;
private static string paralyze_off_msg;
private static string paralyze_message;
string last_pk_name;
int last_pk_time;
static mixed Reaction;
static int ReactionTime;
static int CombatRoundBonus;

int ok_to_kill(object targ);
void miss(int magic, string type, string target_thing);
void set_casting(int x);
void set_paralyzed(int x, string drow, string outta);
void remove_paralyzed();
int query_paralyzed();
int query_casting();
int clean_up_attackers();
int query_modified_exp(object killer, object victim);
int check_death();
int get_damage(object weap);
object query_last_attacker();
object *query_attackers();
object *query_hunters();
void run_away();
void send_messages(int magic, object current, string what, int x);
void set_wimpydir(string str);
void set_wimpy(int x);
string query_wimpydir();
int query_wimpy();
varargs int kill_ob(object victim, int which);
int sight_adjustment();
void continue_attack();
void update_current_skill();
void cease_all_attacks();
private string check_up(string limb);
void execute_attack();
void set_magic_protection(string limb, int x);
void add_magic_protection(mixed *info);
int query_magic_protection(string limb);
int query_magic_round();
string query_paralyze_message();
string query_last_pk();
int query_last_pk_time();
void set_last_pk(string name);
void set_last_pk_time(int time);
void set_combat_round_bonus(int, int);
void add_combat_round_bonus(int, int);
int query_combat_round_bonus();
int query_combat_rounds();

string query_last_pk() { return last_pk_name?last_pk_name:""; }
int query_last_pk_time() { return last_pk_time?last_pk_time:0; }
void set_last_pk(string name) { if (stringp(name) && name != "") last_pk_name=name; }
void set_last_pk_time(int time) { if (intp(time) && time != 0) last_pk_time=time; }

void create() {
  body::create();
}


//  This function is used to initialize various variables

object query_last_attacker()
{
  if(last_attacker)
    return last_attacker;
  // return last_atk_path;
}
void init_attack() {
  init_complex_body();
  hunters = ({});
  attackers = ({});
  wimpydir = "out";
}

//  Remove dead or non-existing objects out of the list of attackers
// Return true if there are still attackers around

int clean_up_attackers() {
  object *full;
  object *nohb;

  full = attackers + hunters;
  if (!full || !sizeof(full)) return any_attack = 0;
  full = filter(full, (:
    (objectp($1) && living($1) && !$1->query_ghost() && !(userp($1) && !interactive($1)))
  :) );

  attackers = filter(full, (: environment($1) == $2 :), environment(this_object()) );
  hunters = full - attackers;
  nohb = filter(attackers, (: (!userp($1) && !query_heart_beat($1)) :) );
  nohb->restart_heart();

  any_attack = sizeof(attackers);
  hunting = sizeof(hunters);
  if (any_attack) {
    last_attacker = attackers[0];
    // last_atk_path = base_name(last_attacker);
  }
  return any_attack;
}

//  This is the kill command.  If the victim is not yet attacked
//  then it is entered first into the list of victims.  If it
//  is already in the list, then it becomes the first entry

varargs int kill_ob(object victim, int which) {
  object *vic_atk;
  int i;

  if (!victim) return 0;
  if (nullp(which)) which = 0;

  vic_atk = (object *)victim->query_attackers();
  if(!vic_atk) vic_atk = ({});
  if(member_array(this_object(), vic_atk) == -1)
    if(!ok_to_kill(victim)) {
      if (victim) // needed in case is_invincible() destructs the mob
      message("my_combat", sprintf("Supernatural forces prevent you "
	"from attacking %s.", (string)victim->query_cap_name()),
       this_object());
      return 0;
    }
  if(victim->query_property("passive")) {
    message("my_combat", "A strange force prevents your attack.", this_object());
    return 0;
  }

  i = member_array(victim, attackers);
  if( i>-1 ) {
    if(attackers[0] == victim) {
      if(!which) notify_fail("You are already doing so!\n");
      return 1;
    }
    attackers[i] = attackers[0];
    attackers[0] = victim;
    return 1;
  }
  attackers = ({ victim }) + attackers;
  any_attack = 1;
  if(!which) victim->kill_ob(this_object(), 1);
  clean_up_attackers();
  victim->clean_up_attackers();
  return 1;
}

void set_attackers(object *what) {
  attackers = what;
  any_attack = 1;
}

//  Called from heart_beat
//  Here is where we see if we are dead or in combat

void continue_attack() {
  object to = this_object();
  object env;
  object new_attacker;
  int tmp;

  if (!to) return;

  env = environment(to);

  if (!env || to->query_ghost() ||
      env->query_property("no attack") ||
      (to->is_player() && !interactive(to)))
        return;

  if (!clean_up_attackers()) {
    casting = 0;
    return;
  }

  // If attacking more than one monster/player pick a random attacker
  // And place it as the first one... 
  tmp = random(sizeof(attackers));
  if (tmp) {
    new_attacker = attackers[tmp];
    attackers[tmp] = attackers[0];
    attackers[0] = new_attacker;
  }

  if (!query_paralyzed()) {
    if (userp(to) && to_int(percent(to->query_hp(), to->query_max_hp())) < wimpy)
      run_away();
    else
      execute_attack();
  }
  else
    message("my_combat", query_paralyze_message(), to);

}

int query_modified_exp(object killer, object victim) {
  int kl;
  int vl;
  int exp;

  if (!killer) return 0;
  if (!victim) return 0;

  if (victim->is_player()) return 0;

  kl = killer->query_level();
  vl = victim->query_level();

  exp = victim->query_exp()/2;

  // Added higher the level the less experience you get
  //  note by Nulvect: this is the old exp cut system
  /*
  ----------------------------------------
  if (vl + kl/3 < kl) {
    exp = exp*2/3;
  }
  ----------------------------------------
  */

  //-- New xp formula by Nesoo below this --

  // modified 2006-07-13 by Nulvect
  // was checking if kl < 20 && kl > vl+9,
  // any mob that low gives almost no exp anyway
  // corinthor stuff ranges level 10 - 15 for ref

  /* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

  if( to_int(kl * 0.50) > vl )
    // No xp for killing something so low
    exp = 0;
  else if( to_int(kl * 0.75) > vl )
  {
    int top = to_int(kl * 0.75);
    int bottom = to_int(kl * 0.50);
    int diff = (top - bottom) * 2;
    float per = 1.0 - (to_float(top - vl) / to_float(diff));
    exp = to_int(exp * per);
  }

  /* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

  return exp;
}
int check_death() {
  object *death;
  int xxx, exp;
  string area;
  if(this_object()->query_hp() > 0) return 1;

  if(!(attackers || last_attacker)) return 1;

  if (!attackers) attackers[0] = last_attacker;
  //    if (!attackers) attackers[0] = new(last_atk_path);
  if(sizeof(attackers) && attackers[0]) {
    attackers[0]->adj_alignment( (int)this_object()->query_alignment() );
    attackers[0]->add_kill((string)this_object()->query_name());
    this_object()->add_death((string)attackers[0]->query_name());
    exp = query_modified_exp(attackers[0], this_object());

    message("info", "You feel more experienced for the kill. "
     "(%^BOLD%^"+add_commas(exp)+"%^RESET%^)", attackers[0]);
    attackers[0]->add_exp(exp);
    if (this_object()->is_player()) {
      /*  Pointless, I'd say...  Who checks kill logs?  (if they even work)
		  log_file("kills",
		    this_object()->query_name()+" ("+(int)this_object()->query_level()+
		    ") was killed by "+attackers[0]->query_name()+" ("+
		    (int)attackers[0]->query_level()+"): "+ctime(time())+"\n");
		  log_file("kills",
		    file_name(attackers[0])+" (uid:"+getuid(attackers[0])+")\n");
      -Nightshade
      */
      if (this_object()->query_recent_outlaw() && !this_object()->query_arena()) {
	message("info", "For doing a good deed, heres "+
	 (this_object()->query_level() * 10)+" gold", attackers[0]);
	attackers[0]->add_money("gold", this_object()->query_level()*10);
	this_object()->set_recent_outlaw(0);
      }
      else if(attackers[0]->is_player()) {
	area = explode(base_name(environment(this_player())), "/")[1];
	if(area == "nopk" || area == "freepk")
	  area = explode(base_name(environment(this_player())), "/")[2];
	attackers[0]->set_last_pk(this_object()->query_name());
	attackers[0]->set_last_pk_time(time());
	log_file("pk", attackers[0]->query_name()+" PKed "+this_player()->query_name()+" on "+
	 ""+ctime(time())+" AREA="+area+"\n");
	if (!wizardp(attackers[0]) && !attackers[0]->query_arena()) {
	  if((attackers[0]->query_race() == "archangel" &&
	    this_object()->query_race() == "demon") ||
	   (attackers[0]->query_race() == "demon" &&
	    this_object()->query_race() == "archangel"));
	  else {
	    if(file_name(environment(this_object()))[0..9] == "/d/freepk/" &&
	     file_name(environment(attackers[0]))[0..9] == "/d/freepk/");
	    else
	      attackers[0]->add_outlaw("pk", 1);
	  }
	}
      }
      //What does this do, exactly?  Left in for possible compatiblity issues
      xxx = sizeof(death = all_inventory(attackers[0]));
      while(xxx--) death[xxx]->notify_kill(this_object());
    }
    this_object()->die((attackers && attackers[0] ? attackers[0] : 0));
    attackers = ({});
    //  Should the player be peaced after death?
    //      hunters = ({});
    return 0;
  }
  return 1;
}

void execute_attack() {
  object *weapons;
  object current;
  mapping Elem;
  string this_spell, target_thing;
  int protection, damage, to_hit, pois, i, num_attacks, x, b;

  if(member_array(this_object(),(object *)attackers[0]->query_attackers())
   == -1) attackers[0]->kill_ob(this_object(), 0);

  if (this_object()->query_rest_type()) return;

  /* for monsters to cast spells */
  if((int)this_object()->query_spell_chance() > random(100)+1) {
    this_spell = (string)this_object()->get_random_spell();
    if(this_spell) this_object()->force_me(this_spell);
  }
  if(this_object()->query_magic_round() && !casting) return;

  num_attacks = query_combat_rounds();

  num_attacks += query_combat_round_bonus();
  if (num_attacks < 1 && random(1000) < 700) num_attacks = 1;

  for(i=0; i<num_attacks; i++) {
    target_thing = (string)attackers[0]->return_target_limb();

    if(casting || !sizeof(weapons))
      current = 0;
    else 
      current = weapons[random(sizeof(weapons))];

    to_hit = (int)attackers[0]->mobility(casting);
    if(casting) to_hit+=3*((int)this_object()->query_stats("intelligence"));
    else {
      to_hit += 35-to_int(percent(query_internal_encumbrance(),
	query_max_internal_encumbrance())/4);
      to_hit += (int)this_object()->query_stats("dexterity");
    }

    if (this_object()->query_blind()) to_hit = to_hit*(3+random(2))/5;

    if(to_hit < random(60)+20) {
      if(!current) miss(casting, 0, target_thing);
      else miss(0, (string)current->query_type(), target_thing);
      continue;
    }
    if(casting) damage = casting;
    else {
      damage = get_damage(current) + random(this_object()->query_sp())/10;
      if(damage > 5 && this_object()->is_player()) this_object()->add_sp(-1);
    }
    protection = (int)attackers[0]->query_current_protection(target_thing);
    damage += (int)this_object()->query_physical()/2 - protection -
    sight_adjustment();
    if(casting && this_object()->query("element")) {
      if(damage > 0) x = (int)attackers[0]->do_elemental(this_object()->query("element"), damage);
      else x = 0;
      this_object()->set("element", 0);
    }
    else {
      if(damage > 0) x = (int)attackers[0]->do_direct_damage(target_thing, damage);
      else x = 0;
    }
    //--------------ELEMENTAL----------------
    // some casting elemental above

    if(current) {
      if(current->query_element() != "unknown") {
	attackers[0]->do_elemental(current->query_element(), current->query_element_amnt());
      }
    }
    else if(this_object()->is_monster()) {
      Elem = this_object()->query_element_attack();
      if(Elem) {
	b = sizeof(keys(Elem));
	while(b--) {
	  attackers[0]->do_elemental(keys(Elem)[b], Elem[keys(Elem)[b]]);
	}
      }
    }

    //------------END ELEMENTAL--------------

    if(current && (pois = (int)current->query_poisoning()) &&
     damage > random(101)) {
      current->add_poisoning(-(pois = random(pois+1)));
      attackers[0]->add_poisoning(pois);
    }
    if(x > 0) {
      add_skill_points("defense", x/ATTACK_DEFENSE_SKILL_MOD);
      add_skill_points("attack", x/ATTACK_ATTACK_SKILL_MOD);
      if(!current && !casting)
	add_skill_points("melee", x/ATTACK_MELEE_SKILL_MOD);
      else if(current) {
	//Was remarked, but I dont see why, keep an eye on this to see
	//if it causes any bugs (concerning current->decay())
	current->decay();
	add_skill_points((string)current->query_type(),
	 x/ATTACK_TYPE_SKILL_MOD);
	if (x > 500)
	  this_object()->add_exp(random(500));
	else
	  this_object()->add_exp(x/ATTACK_DAMAGE_EXP_MOD);
	if(num_attacks > 1) 
	  add_skill_points("double wielding",x/ATTACK_DOUBLE_SKILL_MOD);
      }
    }
    else {
      if(!current && !casting) add_skill_points("melee", 1);
      else if(!casting) {
        add_skill_points((string)current->query_type(),1);
        add_skill_points("attack", 1);
        if(num_attacks > 1 && current) add_skill_points("double wielding", 1);
      }
    }
    send_messages(casting, current, target_thing, x);
  }
  casting = 0;
}

void stop_hunting() {
  hunting = 0;
  hunters = ({});
}
void cease_all_attacks() {
  attackers = ({});
  any_attack = 0;
}

object query_current_attacker() {
  object *att = query_attackers();
  if (sizeof(att)) return att[0];
  else return 0;
}

void add_attacker(object ob) {
  object *att = query_attackers();
  if (member_array(ob, att) == -1)
    attackers = att + ({ ob });
}
void remove_attacker(object ob) { attackers = query_attackers() - ({ ob }); }

void run_away() {
  string *str;

  str = (string *)environment(this_object())->query_exits();
  if(!str || !sizeof(str)) {
    message("my_combat", "There is nowhere to run!!!", this_object());
    return;
  }
  if(this_object()->query_disable()) {
    message("my_combat","You cannot run while doing something else!", this_object());
    return;
  }
  message("my_combat", "You run away.", this_object());
  if(member_array(wimpydir, str) != -1) this_object()->force_me(wimpydir);
  else this_object()->force_me(str[random(sizeof(str))]);
}

void set_wimpydir(string str) {
  if(!stringp(str)) return;
  wimpydir = str;
}

void set_wimpy(int x) { wimpy = x; }

string query_wimpydir() { return wimpydir; }

int query_wimpy() { return wimpy; }

int get_damage(object weap) {
  int damage, melee, attack, double_wielding, use;
  int weap_class;
  mixed f;

  attack = query_skill("attack");
  if(!weap) {
    melee = query_skill("melee");
    damage = random(2+((melee*MAX_MELEE_WC)/100)+((attack*MAX_ATTACK_BONUS)/100));
  }
  else {
    weap_class = (int)weap->query_wc();
    use = query_skill((string)weap->query_type());
    if((int)weap->query_hands() > 1) damage = to_int(use/6.8);
    else damage = (use/7) -5;
    if(num_wielded > 1) {
      double_wielding = query_skill("double wielding");
      if(random(100) > double_wielding/2)
	damage = to_int(damage * 6/10);
      else
	damage = to_int(damage * 8/10);
    }
    if( (weap_class + damage) < 0 ) damage = 0;
    else damage = random( (damage + weap_class + 2)/2 )+((damage + weap_class + 2)/2);
    damage += ((attack*MAX_ATTACK_BONUS)/100);

    //Function calls for weapon specials
    if(!(f=(mixed)weap->query_hit())) return damage;
    if(stringp(f)) message("my_action", f, this_object());
    else
      damage += to_int(call_other(weap, ({ (*f)(), attackers[0] })))*2/3;
  }
  return damage;
}

void set_casting(int x) { casting = x; }

int query_casting() { return casting; }

void set_magic_protection(string limb, int x) {
  if(!magic_protection) magic_protection = ([]);
  if(!limb) magic_protection["overall"] = x;
  else magic_protection[limb] = x;
}

void add_magic_protection(mixed *info) {
  string limb;
  int time, x, i;

  if(sizeof(info) != 3) return;
  limb = info[i];
  x= info[1];
  time = info[2];
  if(!magic_protection) magic_protection = ([]);
  if(!limb) magic_protection["overall"] += x;
  else magic_protection[limb] += x;
  if(time > 0) call_out("add_magic_protection", time, ({ limb, -x, 0 }) );
}

int query_magic_protection(string limb) {
  if(!magic_protection) return 0;
  if(!limb) return magic_protection["overall"];
  else return (magic_protection["overall"] + magic_protection[limb]);
}

void send_messages(int magic, object current, string what, int x) {
  string your_name, my_name;
  string me, you, others, used, type, acolor;
  string *verb, *adverb;
  int i, flying, didflying;

  your_name = (string)attackers[0]->query_cap_name();
  my_name = query_cap_name();
  if(magic) type = "magic";
  else if(current) type = (string)current->query_type();
  else type = "melee";
  acolor = ATTCL;
  i = x/4;
  if(this_object()->query_level() > 20)
    i = x/(this_object()->query_level()/4);
  if(i<0) i=0;
  if(i>11)
    i=11;
  if(i > 10)
    acolor = HIATTCL;
  if(current) used = (string)current->query_name();
  else if(magic) used = "magic";
  else {
    used = limbs[random(sizeof(limbs))];
    while(used == "torso") used = limbs[random(sizeof(limbs))];
  }
  if(x < 1) {
    me = ATTCL+"You hit "+your_name+" ineffectively in the "+what+".";
    you = ATTCL+my_name+" hits you ineffectively in the "+what+".";
    others = ATTCL+my_name+" hits "+your_name+" ineffectively in the "+what+".";
  }
  else if(used== "left leg" || used=="right leg" ||
   used == "back right leg" || used == "back left leg" ||
   used == "left rear leg" || used == "right rear leg")
  {
    didflying=0;
    if (random(100) < 10) {
      if (query_skill("melee") > 200) {
	me = acolor+"You jump up and land a flying drop-kick on "+your_name+".";
	you = acolor+my_name+" jumps up and lands a flying drop-kick on you.";
	others = acolor+my_name+" jumps up and lands a flying drop-kick on "+your_name+".";
	flying = ( (query_skill("melee")/10) + 
	 (query_skill("attack")/10) +
	 (this_object()->query_stats("strength")/2) +
	 (this_object()->query_stats("dexterity")/2) +
	 (random(100)/5) );
	attackers[0]->damage(flying);
	attackers[0]->set_rest_type(3);
	didflying=1;
      }
    } 
    if (!didflying)
    {
      me =acolor+"You kick "+your_name+" with your "+used+".";
      you =acolor+ my_name+" kicks you.";
      others =acolor+ my_name+" kicks "+your_name+".";

    }
  }
  else if(used == "left hand" || used == "right hand" ||
   used == "left paw" || used == "right paw" ||
   used == "left claw" || used == "right claw" ||
   used == "first hand" || used == "second hand" ||
   used == "third hand" || used == "fourth hand")
  {
    didflying=0;
    if (random(100) < 20) {
      if (query_skill("melee") > 150) {
	me = acolor+"You reach down and smash "+your_name+" squarely in the jaw with an uppercut.";
	you = acolor+my_name+" reaches down and smashes you in the jaw with an uppercut.";
	others = acolor+my_name+" reaches down and smashes "+your_name+" squarely in the jaw with an uppercut.";
	flying = ( (query_skill("melee")/12) + 
	 (query_skill("attack")/12) +
	 (this_object()->query_stats("strength")/3) +
	 (this_object()->query_stats("dexterity")/3) +
	 (random(100)/5) );
	attackers[0]->damage(flying);
	didflying=1;
      }
    } 
    if (!didflying)
    {
      me =acolor+"You punch "+your_name+" with your "+used+".";
      you =acolor+ my_name+" punches you.";
      others =acolor+ my_name+" punches "+your_name+".";

    }
  }
  else if(used == "head") {
    if(x < 5) {
      me = acolor+"You bonk "+your_name+" viciously in the head.";
      you = acolor+my_name+" bonks you viciously in the head.";
      others = acolor+my_name+" bonks "+your_name+" viciously in the head.";
    }
    else {
      me = acolor+"You headbutt "+your_name+" furiously.";
      you = acolor+my_name+" headbutts you furiously.";
      others = acolor+my_name+" headbutts "+your_name+" furiously.";
    }
  }
  else {
    if(type == "magic" || type == "melee" || type == "blunt" ||
     type == "two handed" || type == "projectile") {
      verb = ({ "tap", "tickle", "sting", "hurt", "strike", "strike",
       "send", "knock", "slam", "blast", "destroy", "destroy"
      });
      adverb = ({ "innocently", "lightly", 0, "mildly", "badly", 0, 
       "a bone crushing blow", 0, "mercilessly", "powerfully", 0, "utterly"
      });
    }
    else if(type == "blade" || type == "knife" ||type=="axe"||
     type=="flail" || type == "projectile" || type == "ranged") {
      verb = ({ "tap", "tickle", "sting", "graze", "cut", "slice",
       "slice", "shear", "strike", "mutilate", "dismember", "destroy"
      });
      adverb = ({ 0, 0, "sharply", 0, 0, 0, "horribly", "to pieces",
       "letting blood", 0, 0, "utterly"
      });
    }

    me = sprintf("%sYou %s %s%sin the %s with your %s.%%^RESET%%^", 
     acolor,verb[i], your_name,
     (adverb[i] ? " "+adverb[i]+" " : " "), what, used);
    you = sprintf("%s%s %ss you%sin the %s with %s %s.%%^RESET%%^", acolor,my_name, verb[i],
     (adverb[i] ? " "+adverb[i]+" " : " "), what, 
     (string)this_object()->query_possessive(), used);
    others = sprintf("%s%s %ss %s%sin the %s with %s %s.%%^RESET%%^", acolor,  my_name,verb[i],
     your_name, (adverb[i] ? " "+adverb[i]+" " : " "), what,
     (string)this_object()->query_possessive(), used);


  }

  message("my_combat", me, this_object());
  message("my_combat", you, attackers[0]);
  message("other_combat", others, environment(this_object()),
   ({ attackers[0], this_object() }));

}

object *query_hunted() { return hunters || ({}); }
object *query_hunters() { return query_hunted(); }

object *query_attackers() {
  if (clean_up_attackers()) return attackers || ({});
  else return ({});
}

int sight_adjustment() {
  int elight, ret;

  ret = 0;
  elight = effective_light(this_object());
  if(elight >6 || elight < 1)
    ret = random(5);
  if(attackers[0] && attackers[0]->query_invis()) {
    ret += 45 / (1+random((int)this_object()->query_skill("wisdom")));
    attackers[0]->add_sp(-ret);
  }
  if (this_object()->query_blind()) ret += 5+random(40);
  return ret;
}

void miss(int magic, string type, string target_thing) {
  string you, me;
  string *missed;

  you = (string)attackers[0]->query_cap_name();
  me = query_cap_name();
  if(magic) {
    message("my_combat", "Your magic powers fail you.", this_object());
    message("my_combat", sprintf("%s's magic powers fail in an attack "
      "on you.", me), attackers[0]);
    message("other_combat", sprintf("%s's magic powers fail in an attack "
      "on %s.", me, you), environment(this_object()),
     ({ this_object(), attackers[0] }));
    return;
  }
  missed = ({
   "You miss.",
   "You swing, and miss!",
   you+" sidesteps your poorly planned attack.",
   "You decide to daydream a moment instead of attack.",
   "You are too slow this time!",
   you+" dances around as you miss.",
   you+" never knew what missed "+(string)attackers[0]->query_objective()+".",
   you+" dodges your inept attack."
  });
  message("my_combat", MISSCL+missed[random(sizeof(missed))], this_object());
  message("other_combat", sprintf("%s%s misses %s attack on %s.", 
    MISSCL,me, (string)this_object()->query_possessive(), you),
   environment(this_object()), ({ this_object(), attackers[0] }));
  message("my_combat", sprintf("%s%s missed you.", MISSCL,me),attackers[0]);
}

void set_paralyzed(int x, string drow, string outta) {
  if (intp(x) && x == 0) {
    paralyzed = 0;
    remove_call_out("remove_paralyzed");
    paralyze_off_msg = 0;
    return;
  }
  if(archp(this_object())) {
    message("my_action", "Your Archhood just saved you from being "
     "paralyzed.", this_object());
    return;
  }
  if(!drow)
    paralyze_message = DEFAULT_PARALYZE_MESSAGE;
  else
    paralyze_message = drow;
  if(outta) paralyze_off_msg = outta; 
  paralyzed = 1;
  remove_call_out("remove_paralyzed");
  call_out("remove_paralyzed", x);
}

string query_paralyze_message() { return paralyze_message || DEFAULT_PARALYZE_MESSAGE; }

int query_paralyzed() { return paralyzed; }

void remove_paralyzed() { 
  if(!this_object()) return;
  remove_call_out("remove_paralyzed");
  paralyzed = 0;
  if(paralyze_off_msg) message("my_combat", paralyze_off_msg, this_object());
  else
    message("my_combat", "You can move again.", this_object());
  if(paralyze_off_msg) paralyze_off_msg=0;
}

int mobility(int magic) {
  int ret;

  if(magic) ret = 70 - (int)this_object()->query_stats("wisdom");
  else {
    ret = to_int(percent(query_internal_encumbrance(),query_max_internal_encumbrance()))/4;
    ret += 35-(int)this_object()->query_stats("dexterity");
  }
  if(ret > 50) ret = 50;
  if(ret < 0) ret = 0;
  return ret;
}

int query_current_protection(string target_thing) {
  int prot, tmp;

  prot = query_ac(target_thing)+query_skill("defense")/15;
  //  add_skill_points("defense", 2*prot);
  tmp = query_magic_protection(target_thing);
  prot += tmp;
  if(this_object()->query_race() == "dragon") {
    prot += this_object()->query_level() * 3 / 5;
  }
  return prot;
}

void set_magic_round(int x) { magic_round = x; }

int query_magic_round() { return magic_round; }

int ok_to_kill(object targ) {
  int vic_level;

  if(targ->is_invincible()) return 0;
  if(wizardp(this_object())) return 1;
  if(member_array(query_name(), COUNCIL) != -1) return 1;
  if(!this_object()->is_player() || !targ->is_player()) return 1;
  if(!living(targ) || targ->query_ghost()) return 0;
  if(this_object()->query_ghost()) return 0;
  if(targ->query_property("passive")) return 0;
  if(file_name(environment(targ))[0..7] == "/d/nopk/" ||
   file_name(environment(this_object()))[0..7] == "/d/nopk/") return 0;
  if((vic_level = targ->query_level()) <= NEWBIE_LEVEL && !this_object()->query_arena())
    return 0;      /* can't kill newbies */
  if((this_object()->query_level()) <= NEWBIE_LEVEL && !this_object()->query_arena())
    return 0;

  return 1;
}

void set_combat_round_bonus(int x, int seconds) {
  if (seconds != -1)
    DELAY_D->add_delay(seconds, this_object(), "set_combat_round_bonus", ({ CombatRoundBonus, -1 }), 0);
  CombatRoundBonus = x;
}
void add_combat_round_bonus(int x, int seconds) {
  if (seconds != -1)
    DELAY_D->add_delay(seconds, this_object(), "add_combat_round_bonus", ({ -x, -1 }), 0);
  CombatRoundBonus += x;
}
int query_combat_round_bonus() { return CombatRoundBonus; }
int query_combat_rounds() {
  int num_attacks;
  object *weapons;

  if (casting) return 1;

  else {
    if(!(num_attacks = sizeof(weapons=distinct_array(query_wielded())))) {
      num_attacks = 1;
      if(random(100) > 160-query_skill("attack"))
	num_attacks++;
      if (this_object()->query_race()=="raknid")
	num_attacks = 2 * num_attacks;
    }

    num_attacks += this_object()->query_skill("attack")/(random(50)+100);    
  }
  if(this_object()->query_class() == "fighter") {
    if (num_attacks > MAX_NUM_ATTACKS + 2)
      num_attacks = MAX_NUM_ATTACKS + 2;
  }
  else {
    if (num_attacks > MAX_NUM_ATTACKS)
      num_attacks = MAX_NUM_ATTACKS;
  }

  return num_attacks;
}
