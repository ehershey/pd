//      /std/monster.c
//      from the Nightmare mudlib
//      inheritable code for npc's
//      created by Descartes of Borg september 1992
//      added set_unique() - seeker
#include <std.h>
#include <move.h>
#include <objects.h>
#include <daemons.h>
#include <elemental.h>
#include <rest.h>
//inherit LIVING;
inherit "/wizards/nulvect/std/living";
object tmp, exp_share;
static status heart_beat_on;
float exp_share_perc;
int level, patrol, pon, pcnt, dragon_level, unique;
string *pdirs;
int _Disabled;
static int speed;
static int moving;
static mapping Elements;
mapping emotes, speech, spells;
string body_type;
private static mixed __Die;
int swarm;
void set_exp_share(object ob, float x);
void set_swarm(int x);
varargs void die(mixed killer);
void set_unique(int x);
int test_heart();
void set_spell_chance(int x);
void set_spells(string *arr);
void set_race(string str);
void set_dragon_level(int x);
int query_dragon_level();
void set_patrol(int x, string *dirs);
void do_patrol();
string return_chat();
string return_achat();
void set_exp(int x);
void set_level(int x);
int query_level();
void move_around();
void set_emotes(int x, string *arr, int att);

mixed query_aggressive();
void set_aggressive(mixed arg);
int query_swarm();
void do_swarm();

void create() {
    living::create();
    emotes = ([]);
    speech = ([]);
    spells = ([]);
    enable_commands();
    seteuid(getuid(this_object()));
    init_limb_data();
    init_stats();
    init_skills(0);
    init_living();
    set_heart_beat(heart_beat_on = 1);
    speed = 0;
    set_gender("neuter");
    _Disabled = 0;
    Elements = ([]);
}
void heart_beat() {
  object to = this_object();
  string pre;
  string msg;
  string lang;
  string *langs;

  living::heart_beat();
  if (!to) return;

  if (pdirs)
    do_patrol();

  if (speed && moving >= speed)
    move_around();
  else
    moving++;

  if (swarm)
     do_swarm();

  if (to->query_current_attacker()) {
    switch (to->query_rest_type()) {
      case SLEEP:
        to->force_me("wake");
      break;
      case SIT: case REST: case LAY:
        to->force_me("stand");
      break;
      default:
    }
    pre = "attack ";
  }
  else pre = "";

  if (emotes[pre+"chance"] > random(100)) {
    msg = emotes[pre+"msg"][random(sizeof(emotes[pre+"msg"]))];
    message("emote", msg, environment(to), ({ to }) );
  }

  if (sizeof(langs = keys(speech))) {
    lang = langs[random(sizeof(langs))];
    if (speech[lang][pre+"chance"] > random(100)) {
      msg = speech[lang][pre+"msg"][random(sizeof(speech[lang][pre+"msg"]))];
      this_object()->force_me("speak in "+lang+" "+msg);
    }
  }

  if (!test_heart()) set_heart_beat(heart_beat_on = 0);
}

mixed query_aggressive() { return query("aggressive"); }
void set_aggressive(mixed arg) {
  if (!( intp(arg) || stringp(arg) )) return;
  set("aggressive", arg);
}

int query_swarm() { return swarm; }

void do_swarm() {
  object to = this_object();
  object *killme;

  killme = filter(all_inventory(environment(to)),
    (: ($1->is_player() && $1->query_current_attacker() &&
       member_array($1, $(to)->query_attackers()) == -1) :) );

  foreach (object pl in killme) {
    to->force_me("kill "+pl->query_name());
    to->kill_ob(pl);
    // kill command might not work if disabled, etc
  }

}


void set_exp_share(object ob, float x)
{
 exp_share = ob;
 exp_share_perc = x;
 set_exp(0);
}

// This was added to prevent reduction of mob's naturally inflated hp
void fix_vital_bonus() { return; }

void set_element_attack(string elem, int x) {
 if(member_array(elem, ELEMENTS) == -1)
   return;
 if(x > 100)
   x = 100;
 Elements[elem] = x;
}

mapping query_element_attack() {
 return Elements;
}

void add_exp(int x)
{
 if (exp_share)
 exp_share->add_exp( to_int(x * 75/100)  );
 return ::add_exp(0);
}
void set_unique(int x)
{
 unique = x;
}
void set_swarm(int x)
{
 swarm = x;
}
int query_heart() { return query_heart_beat(); }
void restart_heart() { set_heart_beat(1); }
void init() {
    mixed tmp;
    ::init();
    if(!heart_beat_on) set_heart_beat(heart_beat_on = 1);
    if(this_player()->query_invis()) {
        if(wizardp(this_player())) return;
        if(random(101) < (int)this_player()->query_level()) return;
    }
    if(this_player()->query_ghost()) return;
    if(this_player()->is_player()) {
        if(tmp = query("aggressive")) {
            if(intp(tmp) && tmp > (int)this_player()->query_stats("charisma"))
              kill_ob(this_player(), 0);
            else if(stringp(tmp)) call_other(this_object(), tmp);
        }
    }
}
void set_name(string str) {
   set_living_name(str);
   ::set_name(str);
   if(query_level() < 1) set_level(1);
}
varargs void die(mixed killer) {

  if (!objectp(killer)) killer = 0;

  if (functionp(__Die)) {
    if (!((int)((*__Die)(killer)))) return;
  }

  set_heart_beat(0);

  living::die(killer);

  if (stringp(__Die))
    message("other_action", __Die, environment(this_object()),
      ({ this_object() }) );
  else
    message("other_action", capitalize(query_name())+
      " drops %^RED%^dead%^RESET%^ before you.",
      environment(this_object()), ({ this_object() }));

  this_object()->remove();
}

int query_npc() { return 1; }
void set_id(string *str)
{
 if(previous_object() != get_object("/std/ride"))
 str += ({ "monster" });
 ::set_id(str);
}
varargs void move_player(mixed dest, string message) {
   object prev;
   string here,going,temp1,temp2,temp3;
   prev = environment(this_object());
   here = file_name(prev);
   if (stringp(dest)) {
     if (sscanf(dest,"/%s",temp1)!=1) {
       sscanf(here,"/%s",temp1);
       going = "";
       while(sscanf(temp1,"%s/%s",temp2,temp3)==2) {
         going = going + "/"+temp2;
         temp1 = temp3;
       }
       temp1 = dest;
       if (file_size(going+"/"+temp1+".c") != -1) {
         dest = going+"/"+temp1;
       }
     }
   }
   if(move(dest) == MOVE_OK) {
      say("%^GREEN%^%^BOLD%^"+query_cap_name() + " arrives.%^RESET%^",this_object());
      tell_room(prev, "%^GREEN%^%^BOLD%^"+query_cap_name() + " leaves " + message + ".");
      }
}
/* Call_out taken out of move_around by Hanse 1/4/93 */
void move_around() {
   string *exits, exit;
    if(!this_object()) return;
     if (environment(this_object())->query_exits()==({})) return;
   if(environment(this_object()))
       exits = (string*)environment(this_object())->query_exits();
   else exits = 0;
 if (exits)   exit = exits[random(sizeof(exits))];
  if (exits)
 this_object()->force_me(exit);
   
   moving=0;
}
// Set_Patrol by seeker May 26 2000
void set_patrol(int x, string *dirs)
{
 
 if (!x)
   return;
 if (!dirs)
   return;
 pon = 0;     // direction currently on..
 pcnt = 0;    // game ticks waiting for move
 pdirs = dirs; // directions
 patrol = x;  // speed of patrolling
}
void do_patrol()
{
 if (pcnt < patrol)
   {
    pcnt++;
    return;
   }
 pcnt = 0;
 this_object()->force_me(pdirs[pon]);
 pon++;
 if (pon > sizeof(pdirs)-1)
  {
   pon = 0;
  }
}
void set_moving(int i) { moving = i; }
void set_speed(int i) { speed = i; }
    
string query_short()
{
 string seeker;
 int i;
 seeker = ::query_short();
 i = to_int(percent(query_hp(), query_max_hp()));
 if (i < 35)
   {
    seeker += " (dying)";
   } else
 if (i < 65)
   {
    seeker += " (bleeding)";
   } else
 if (i < 95)
   {
    seeker += " (injured)";
   }
      
 return seeker;
}
void set_level(int x) {
    float calc;
    if (!x) x = 1;
    level = x;
    calc = x;
    set_overall_ac(x + 9);
    set_skill("melee", (x*3));
    set_skill("attack", (x*4));
    set_skill("defense", (x*4));
    set_skill("double wielding", (x*4));
    set_skill("charging", (x*4));
    set_skill("rage", (x*4));
    set_skill("axe", (x*4));
    set_skill("blade", (x*4));
    set_skill("blunt", (x*4));
    set_skill("breath", (x*4));
    set_skill("claw", (x*4));
    set_skill("flail", (x*4));
    set_skill("knife", (x*4));
    set_skill("projectile", (x*4));
    set_skill("ranged", (x*4));
    set_skill("tail", (x*4));
    set_skill("agility", (x*4));
    set_skill("bargaining", ((x*2)+(x/2)));
    set_skill("discipline", (x*4));
    set_skill("entertainment", (x*4));
    set_skill("euhony", (x*4));
    set_skill("murder", (x*4));
    set_skill("perception", (x*4));
    set_skill("stealing", (x*4));
    set_skill("stealth", (x*4));
    set_skill("ferocity", (x*4));
    set_skill("valor", (x*4));
    set_skill("belief", (x*4));
    set_skill("clairvoyance", (x*4));
    set_skill("conjuring", (x*4));
    set_skill("faith", (x*4));
    set_skill("healing", (x*4));
    set_skill("magic attack", (x*4));
    set_skill("magic defense", ((x*2)+(x/2)));
    set_skill("nature", (x*4));
    set_skill("necromancy", (x*4));
    set_skill("psionics", (x*4));
    set_skill("pyromancy", (x*4));
    set_skill("summoning", (x*4));
    set_skill("wizardry", (x*4));
 if (x <= 50) {
    set_stats("constitution", to_int(10+(4.5*pow(2.0, calc/15.0))));
    set_stats("strength", to_int(10+(4.5*pow(2.0, calc/15.0))));
    set_stats("intelligence", to_int(10+(4.5*pow(2.0, calc/15.0))));
    set_stats("wisdom", to_int(10+(4.5*pow(2.0, calc/15.0))));
    set_stats("dexterity", to_int(10+(4.5*pow(2.0, calc/15.0))));
    set_stats("charisma", to_int(10+(4.5*pow(2.0, calc/15.0))));
 }
 else {
    set_stats("constitution", to_int(35+(5*pow(2.0, calc/25.0))));
    set_stats("strength", to_int(35+(5*pow(2.0, calc/25.0))));
    set_stats("intelligence", to_int(35+(5*pow(2.0, calc/25.0))));
    set_stats("wisdom", to_int(35+(5*pow(2.0, calc/25.0))));
    set_stats("dexterity", to_int(35+(5*pow(2.0, calc/25.0))));
    set_stats("charisma", to_int(35+(5*pow(2.0, calc/25.0))));
 }
  if (x <= 20)
    {
    set_max_hp((x * (x-3))*4/2);
    }
  if ( x <= 10)
    {
    set_max_hp( (x * 20) + 64);
    }
  if (x >= 20)
    set_max_hp((x * (x-3))*4/2);
    set_hp(query_max_hp());
    set_max_mp(query_max_hp());
    set_mp(query_max_mp());
     set_max_sp(x*20);
    set_sp(query_max_sp());
    if(x > 24)
        set_exp( 2000 * x );
    else
        set_exp( (x*x*x*53) / 16 );
}
int query_level() { return level; }
// Added by Valodin, June 28, 1993
// Sets the body type to a certain race using the race daemon
void set_body_type(string str) {
  mapping monster_bod;
    int mag, max_mag;
  string *mon_limbs;
  int i, max;
  if(!str || !RACE_D->is_monster_race(str))
    str = "human";
    mag = query_mp();
    max_mag = query_max_mp();
  init_limb_data();
  monster_bod = (mapping)RACE_D->monster_body(str, query_max_hp());
  for(i = 0, max = sizeof(mon_limbs = keys(monster_bod)); i < max; i++)
    add_limb(mon_limbs[i], monster_bod[mon_limbs[i]]["limb_ref"], 
             monster_bod[mon_limbs[i]]["max_dam"], 0, 0);
  set_wielding_limbs((string *)RACE_D->query_monster_wielding_limbs(str));
  set_fingers((int)RACE_D->query_monster_fingers(str));
  body_type = str;
    set_mp(mag);
    set_max_mp(max_mag);
}
string query_body_type()
{
  return body_type;
}
void set_spell_chance(int x) {
    if(!spells) spells = ([]);
    spells["chance"] = x;
}
void set_spells(string *arr) {
    if(!spells) spells = ([]);
    spells["commands"] = arr;
}
int query_spell_chance() { 
    if(spells) return spells["chance"];
    else return 0;
}
string *query_spells() {
    if(spells) return spells["commands"];
    else return 0;
}
string get_random_spell() {
    if(!spells) return 0;
    if(sizeof(spells["commands"]) <2) return spells["commands"][0];
    else return spells["commands"][random(sizeof(spells["commands"]))];
}
void set_exp(int x) {
    if( x > (int)ADVANCE_D->get_exp(level) )
        player_data["general"]["experience"] = (int)ADVANCE_D->get_exp(level);
    else player_data["general"]["experience"] = x;
}
// These two functions remain for backwards Nightmare 1.* and 2.* compat
void set_chats(int x, string *arr) { set_emotes(x, arr, 0); }
void set_achats(int x, string *arr) { set_emotes(x, arr, 1); }
void set_emotes(int x, string *arr, int att) {
    emotes[(att ? "attack chance" : "chance")] = x;
    emotes[(att ? "attack msg" : "msg")] = arr;
}
void set_speech(int x, string lang, string *arr, int att) {
    speech[lang] = ([ (att ? "attack chance" : "chance"): x,
      (att ? "attack msg" : "msg"): arr ]);
}
void set_alignment(int x) { player_data["general"]["alignment"] = x; }
string query_race() { return query("race"); }
int test_heart() {
    object env;
    object *inv;
    int i;
   if( (query_mp() < query_max_mp()) || (query_hp() < query_max_hp()) ||
      (query_sp() < query_max_sp()) ) return 1;
    if(!(env = environment(this_object()))) return 0;
    if (query_hp() < 1) return 1;
    if(query_current_attacker() || speed) return 1;
    i = sizeof(inv = all_inventory(env));
    while(i--) 
      if(interactive(inv[i]) || inv[i]->query("aggressive")) return 1;
    return 0;
}
int query_heart_status() { return heart_beat_on; }
void receive_message(string cl, string msg) {
   if( this_object()->query("posessed") )
      message("info", "%^RED%^%%%^RESET%^ "+msg, this_object()->query("posessed"), 0);
   if ( function_exists("catch_tell", this_object() ) )
     this_object()->catch_tell(msg);
}
void set_languages(string *langs) {
    int i;
    
    i = sizeof(langs);
    while(i--) set_lang_prof(langs[i], 10);
}
void set(string str, mixed val) {
    ::set(str, val);
    if(str == "race") LANG_D->init_languages(this_object());
}
void set_die(mixed val) {
   if(functionp(val) && geteuid(this_object()) != geteuid(val)) return;
    __Die = val;
}
mixed query_die() { return __Die; }
void set_race(string str) { set("race", str); }
void set_dragon_level(int x) { dragon_level = x; }
int query_dragon_level() { return dragon_level; }
int is_monster() { return 1; }

mixed *local_commands() {
  return commands();
}
