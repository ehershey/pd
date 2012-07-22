//      /std/living/body.c
//      from the Nightmare mudlib
//      the code for the limbs system used by the Nightmare mudlib
//      based on the TMI LOS system by Brian with help from Buddha
//      written by Descartes of Borg september 1992

#include <std.h>
#include <daemons.h>
#include <objects.h>
#include <limb_status.h>
#include <damage.h>
#include <damage_types.h>

inherit CONTAINER;

mixed *deaths;
mapping severed, body;
static mapping wielded;
static string target_limb;
string *limbs;
int all_my_fingers;
static int num_wielded;
mapping _BodyData = ([]);

string *query_walking_limbs();
int query_mobile();
int query_limb_status(string limb);
int query_usable(string limb);
int query_useable(string limb);
string *query_limbs_wielded();
void set_wielding_limbs(string *str);
int check_on_limb(string limb);
string *query_wielding_limbs();
string type_ok(string type, string limb);
void init_limb_data();
void set_fingers(int x);
int query_fingers();
void set_overall_ac(int ac);
void set_ac(string limb_name, int ac);
int add_limb(string limb_name, string limb_ref, int max_dam, int curr_dam, int limb_ac);
int remove_limb(string limb_name);
int query_ac(string limb_name);
varargs int do_damage(mixed limb, int damage, int type, int flags, mixed source, string zone);
int do_direct_damage(string limb, int damage);
void do_limb_damage(string limb, int dam);
varargs void set_last_damage(mixed source, string zone);
string query_last_damage_zone();
mixed query_last_damage();
int query_last_damage_time();
static private varargs int apply_reductions(int damage, int type, string limb);
string query_reference(string limb);
string equip_weapon_to_limb(object weap, mixed limb);
string equip_armour_to_limb(object arm, string *limb);
object query_weapon(string limb);
string *query_armour(string limb);
object *query_armour_ob(string limb);
int remove_armour_from_limb(object arm, string *limb);
int remove_weapon_from_limb(object ob);
string *query_limbs();
string return_limb();
string return_target_limb();
int query_is_limb(string limb);
string *query_severed_limbs();
void add_wielding_limb(string);

void create() {
  container::create();
  _BodyData = ([]);
}

//  This function initializes the variables
//  This should only be called when there is NO limb data yet
mapping query_body_mapping() { return body; }
void init_limb_data() {
  body = ([]);
  limbs = ({});
  wielded = ([]);
  severed = ([]);
}


//  This function is only for lazy wizzes to use when creating monsters!!

void set_overall_ac(int x) {
  int i;

  for(i=0; i<sizeof(limbs); i++) {
    if(limbs[i] != "torso") set_ac(limbs[i], x);
    else set_ac("torso", (2*x));
  }
}

void set_ac(string limb_name, int ac) {
  body[limb_name]["ac"] = ac;
}


//  This function adds limbs to a player or monster
//  The values passed to it mean the following:
//  limb_name: The name of the limb being added
//  limb_ref: The name of other limbs that should be lost when this
//      limb is lost, or FATAL is losing it is fatal, or "" if nothing
//      else should happen.
//  max_dam:  The maximum damage the limb can take before being lost
//  curr_dam:  How much damage has been done to the limb thus far.  This
//      allows you to create wounded monsters.
//  limb_ac:  How much protection the limb has.  By setting it to >0, you
//      set it's natural ac
//  NOTE:  In order to make a creature with 4 arms, each arm must have a
//      distinctive name, like "lower right arm", "right arm", "lower left
//      arm", "lower right arm"

int add_limb(string limb_name, string limb_ref, int max_dam, int curr_dam, int limb_ac) {
  body[limb_name] = ([ "limb_ref": limb_ref, "max_dam": max_dam, "damage": curr_dam, "ac": limb_ac ]);
  if(!limbs) limbs = ({});
  limbs += ({ limb_name });
  body[limb_name]["armour"] = ({});
  body[limb_name]["armour_ob"] = ({});
  body[limb_name]["weapons"] = 0;
  if(!severed) return 1;
  if(severed[limb_name]) map_delete(severed, limb_name);
  return 1;
}

// this recalculates max damage for each limb, called when max hp changes
// max damage is calculated in RACE_D's body() function now
void augment_body(int x) {
  string race;
  int max_hp, monster;
  max_hp = this_object()->query_max_hp();
  monster = this_object()->is_monster();
  race = this_object()->query_body_type();
  if (!race || !monster) {
    race = this_object()->query_race();
  }
  foreach (string l in limbs) {
    body[l]["max_dam"] = RACE_D->query_max_dam(l, race, max_hp, monster);
  }
}

void regenerate_limb(string limb) {
  object to = this_object();
  string race = to->query_body_type();
  int monster = to->is_monster();
  mapping limbdata;
  string child;
  int max;

  if (member_array(limb, query_severed_limbs()) == -1)
    return;

  if (!race || !monster)
    race = to->query_race();

  limbdata = RACE_D->query_limb(limb, race);
  if (!sizeof(limbdata)) return;

  max = RACE_D->query_max_dam(limb, race, to->query_max_hp(), monster);

  if (limbdata["fatal"])
    child = "FATAL";
  else if (sizeof(limbdata["children"]))
    child = limbdata["children"];
  else
    child = "";

  add_limb(limb, child, max, 0, limbdata["ac"]);

  if (limbdata["wield"])
    add_wielding_limb(limb);
}

//  This function removes a limb

int remove_limb(string limb_name) {
  if(body[limb_name]) {
    severed[limb_name] = body[limb_name]["limb_ref"];
    map_delete(body, limb_name);
    limbs -= ({ limb_name });
    return 1;
  }
  return 0;
}

//  This function returns a random limb

string return_limb() {
  return limbs[random(sizeof(limbs))];
}

//  This function returns a random limb, giving weight to
//  those limbs that can take the most damage

string return_target_limb() {
  string tmp_lmb;
  int res, i, count;

  if(target_limb && !query_is_limb(target_limb)) target_limb = 0;
  if(target_limb) {
    tmp_lmb = target_limb;
    target_limb = 0;
    if(random(120) > (int)this_object()->query_skill("defense"))
      return tmp_lmb;
  }
  count = member_array("torso", limbs);
  i = 0;
  while(i++ < ((sizeof(limbs))/2))
    if( (res=random(sizeof(limbs))) == count ) break;
  return limbs[res];
}

string query_torso() {
  string race = this_object()->query_body_type() || this_object()->query_race();
  mapping limbdata = RACE_D->query_race_limb_data(race);
  string *torso;
  limbdata = filter(limbdata, (: $2["importance"] == 1 :) );
  torso = keys(limbdata);
  return torso[random(sizeof(torso))];
}

string *query_limbs() { return limbs; }

int query_is_limb(string limb) {
  if(member_array(limb, limbs) != -1) return 1;
  else return 0;
}

string *query_walking_limbs() {
  string race;

  race = this_object()->query_body_type();
  if (!race || !this_object()->is_monster())
    race = this_object()->query_race();

  return RACE_D->query_required_limbs("walk", race);
}

int query_mobile() {
  object to = this_object();
  string *walk;
  string *sev;
  walk = to->query_walking_limbs();
  if (!sizeof(walk)) return 0;
  sev = filter(walk, (: $(to)->query_useable($1) == 0 :) );
  // if > 40% of walking limbs are not useable, we are not mobile
  return sizeof(sev)*100/(sizeof(walk) || 1) < 40;
}

int query_limb_status(string limb) {
  int ret = 0;
  if (!limb || !query_is_limb(limb))
    return LIMB_ERROR;
  if (member_array(limb, this_object()->query_wielding_limbs()) != -1)
    ret |= LIMB_WIELDABLE;
  if (member_array(limb, this_object()->query_limbs_wielded()) != -1)
    ret |= LIMB_WIELDING;
  if (sizeof(this_object()->query_armour_ob(limb)))
    ret |= LIMB_WEARING;
  if (member_array(limb, this_object()->query_severed_limbs()) != -1)
    ret |= LIMB_SEVERED;
  if (this_object()->query_crippled(limb))
    ret |= LIMB_CRIPPLED;
  return ret;
}

int query_usable(string limb) { return query_useable(limb); }
int query_useable(string limb) {
  int s = query_limb_status(limb);
  if (s & LIMB_ERROR || s & LIMB_SEVERED || s & LIMB_CRIPPLED)
    return 0;
  return 1;
}


int query_max_dam(string limb) {
  if(body[limb]) return body[limb]["max_dam"];
}

int query_dam(string limb) {
  if(body[limb]) return body[limb]["damage"];
}

string query_reference(string limb) {
  if(body[limb]) return body[limb]["limb_ref"];
}

int damage(int x, string *str)
{
  string bod;
  int ret;

  bod = return_target_limb();
  ret = do_damage(bod, x);
  check_on_limb(bod);
  return ret;
}

/* limb: can be a limb name (string), array of limbs (string array),
 *   "none" or 0 for no limbs, "all" or 1 for all limbs,
 *   "target" or 2 for a target limb (aim command and limb size matter)
 *   "random" or 3 for a random limb
 * damage: must be > 0
 * type: optional damage type bitmask from damage_types.h
 * flags: optional damage modifier bitmask from damage.h
 * source: actual object that did the damage (should be living),
 *   or short string description like "falling rocks"
 */
varargs int do_damage(mixed limb, int damage, int type, 
int flags, mixed source, string zone) {
  object to = this_object();

  if (nullp(limb) || nullp(damage)) return 0;
  if (nullp(type)) type = DAMAGE_OTHER;
  if (nullp(flags)) flags = 0;
  if (!objectp(source) && !stringp(source)) {
    if (this_player())
      source = this_player();
    else if (previous_object() && previous_object()->is_living())
      source = previous_object();
  }
  // we really want to track this, so try our best to get some info...
  if (objectp(source) && !source->is_living())
    source = source->query_short() || source->query_name();

  // reduce damage for players
  if (to->is_player() && !(flags & DAMAGE_NO_PLAYER_REDUCE))
    damage = damage/2;

  // AC damage reduction, does not count strengths/weaknesses of armour
  if (!(flags & DAMAGE_BYPASS_ARMOUR))
    damage = damage - to->query_current_protection(limb);

  if (damage <= 0)
    return 0;

  switch (typeof(limb)) {

  case "string":
    switch (limb) {
    case "none":
      flags |= DAMAGE_NO_LIMBS;
      break;
    case "all":
      limb = query_limbs();
      break;
    case "target":
      limb = ({ return_target_limb() });
      break;
    case "random":
      limb = ({ return_limb() });
      break;
    default:
      limb = ({ limb });
    }
    break;

  case "int":
    switch (limb) {
    case 0:
      flags |= DAMAGE_NO_LIMBS;
      break;
    case 1:
      limb = query_limbs();
      break;
    case 2:
      limb = ({ return_target_limb() }) ;
      break;
    case 3:
      limb = ({ return_limb() });
      break;
    }
    break;

  case "array":
    // just here to avoid the default:
    break;

  default:
    flags |= DAMAGE_NO_LIMBS;
  }

  if (!(flags & DAMAGE_NO_LIMBS)) {
    foreach (string thislimb in limb) {
      int limbdam = damage;

      if (!to->query_is_limb(thislimb)) continue;

      if (!(flags & DAMAGE_BYPASS_STRENGTHS))
        limbdam = to->apply_reductions(limbdam, type, thislimb);

      if (limbdam > 0) {
        to->do_limb_damage(thislimb, limbdam);

        // sever the limb if total limb damage >= maximum for that limb
        // exceptions: do not sever if NO_SEVER flag is set on this damage,
        //   or if NONLETHAL flag is set and losing this limb is fatal
        if (!( (flags & DAMAGE_NO_SEVER) ||
          (flags & DAMAGE_NONLETHAL &&
           (string)to->query_reference(thislimb) == "FATAL" &&
           to->query_dam(thislimb) >= to->query_max_dam(thislimb)) ) )
          to->check_on_limb(thislimb);
      }
    }
  }

  if (!(flags & DAMAGE_NO_HP)) {

    if (!(flags & DAMAGE_BYPASS_STRENGTHS))
      damage = to->apply_reductions(damage, type);

    if (damage > 0) {

      if (flags & DAMAGE_NONLETHAL &&
       to->query_hp() - damage < 1 &&
       to->query_hp() >= 1)
        to->set_hp(1);
      else
        to->add_hp(-damage);

      to->show_status_line();
    }
  }

  if (nullp(zone) && !( environment(to) && (zone = environment(to)->query_zone()) ) )
    zone = "pk";

  set_last_damage(source, zone);

  return damage;
}

int do_direct_damage(string limb, int damage) {
  return do_damage(limb, damage, DAMAGE_OTHER, DAMAGE_BYPASS_ARMOUR);
}

void do_limb_damage(string limb, int dam) {
  object to = this_object();
  if (!to->query_is_limb(limb)) return;
  // the difference here is because mobs have different amounts of max limb
  //   damage than players do, for some reason
  if (to->is_player())
    dam /= 1;
  else
    dam /= to->query_level()*1;
  to->heal_limb(limb, -dam);
}

varargs void set_last_damage(mixed source, string zone) {
  if (nullp(source)) source = 0;
  if (nullp(zone)) zone = "";
  if (!_BodyData) _BodyData = ([]);
  _BodyData["last damage"] = source;
  _BodyData["last damage time"] = time();
  _BodyData["last damage zone"] = zone;
}
mixed query_last_damage() { return _BodyData["last damage"] || 0; }
string query_last_damage_zone() { return _BodyData["last damage zone"] || ""; }
int query_last_damage_time() { return _BodyData["last damage time"] || 0; }

static private varargs int apply_reductions(int damage, int type, string limb) {
  object to = this_object();
  object *armours;
  int totalstr = 100;
  int count = 0;

  if (!nullp(limb) && to->query_is_limb(limb))
    armours = to->query_armour_ob(limb);
  else
    armours = filter(all_inventory(to), (: $1->query_worn() :) );

  // scrapping the 'armours provide 75% resistance to player' thing, confusing
  // now just doing 100%
  // note: this is not AC
  if (sizeof(armours)) {
    foreach (mapping resistances in armours->query_resistances()) {
      if (!resistances) continue;
      foreach (int typestr, int resistance in resistances) {
        if (type & typestr) {
          count++;
          totalstr += resistance;
        }
      }
    }
  }

  foreach (int typestr, int resistance in to->query_resistances()) {
    if (type & typestr) {
      count++;
      totalstr += resistance;
    }
  }

  if (totalstr != 0 && count > 0)
    damage = damage * (totalstr - (count*100)) / 100;

  return damage;
}

int query_ac(string limb) {
  int tmp_ac, i;

  if(!body) return 0;
  if(!body[limb]) return 0;
  tmp_ac = 0;
  i = sizeof(body[limb]["armour_ob"]);
  while(i--)
    tmp_ac += (body[limb]["armour_ob"][i] ? (int)body[limb]["armour_ob"][i]->query_ac() : 0);
  return tmp_ac;
}

void remove_wielding_limb(string str) {
  if (member_array(str, limbs) == -1) return;
  body[str]["wieldable"] = 0;
}

string equip_weapon_to_limb(object weap, mixed limb) {
  string *ls;
  if (stringp(limb)) {
    limb=replace_string(limb, ", ", ",");
    limb=replace_string(limb, " ,", ",");
    ls=explode(limb,",");
  }
  else if (arrayp(limb) && sizeof(limb) && stringp(limb[0])) {
    ls = limb;
  }
  else
    return "Bad limb specification.";
  foreach (string limb1 in ls) {
    if(member_array(limb1, limbs) == -1)
      return "You have no "+limb1+"!";
    if(wielded[limb1]) return "You are already wielding something in your "+limb1+"!\n";
    if(member_array("shield", body[limb1]["armour"]) != -1)
      return "You cannot wield a weapon while wearing a shield in your "+limb1+".\n";
    if(!body[limb1]["wieldable"])
      return "You cannot wield a weapon with a "+limb1+"!\n";

    body[limb1]["ac"] += (int)weap->query_ac();
    body[limb1]["weapons"] = weap;
    wielded[limb1] = weap;
  }
  num_wielded++;
  return 0;
}

string equip_armour_to_limb(object arm, string *limb) {
  int i;
  function f;
  string y, type;

  type = (string)arm->query_type();
  i = sizeof(limb);
  while(i--) if(y=type_ok(type, limb[i])) return y;
    //    if(functionp(f = (mixed)arm->query_wear()) && !((*f)())) return "NO";
  i = sizeof(limb);
  while(i--) {
    body[limb[i]]["ac"] += (int)arm->query_ac();
    body[limb[i]]["armour"] += ({type});
    body[limb[i]]["armour_ob"] += ({ arm });
  }
  return 0;
}

string type_ok(string type, string limb) {
  int worn, x, i;

  if(!body[limb]) return "You have no "+limb+"!";
  if(member_array(type, body[limb]["armour"]) != -1) worn = 1;
  else worn = 0;
  switch(type) {
  case "shield":
    if(worn) return "You are already wearing a shield!\n";
    else if(wielded[limb])
      return "You cannot wear a shield while you are wielding a weapon in your "+limb+".\n";
    else return 0;
    break;
  case "body armour":
    if(member_array("armour", body[limb]["armour"]) != -1)
      return "You cannot wear regular armour with body armour.\n";
    else if(worn) return "You are already wearing body armour!\n";
    else return 0;
    break;
  case "ring":
    i = 0;
    x = sizeof(body[limb]["armour"]);
    while(x--) 
      if(body[limb]["armour"][x] == "ring") i++;
    if(i >= all_my_fingers)
      return "You do not have that many fingers on your "+limb+".";
    else return 0;
    break;
  case "armour":
    if(member_array("body armour", body[limb]["armour"]) != -1)
      return "You may not wear body armour and armour at the same time.\n";
    else if(worn) return "You may only wear one piece of body armour at a time.\n";
    else return 0;
    break;
  default:
    if(worn) return "You may only wear one armour of type "+type+" at a time.\n";
    else return 0;
    break;
  }
  return "Error in wearing armour.\n";
}

string *query_armour(string limb) {
  if(body[limb]) return body[limb]["armour"];
  else return 0;
}

object *query_armour_ob(string limb) {
  if(body[limb]) return body[limb]["armour_ob"];
  else return 0;
}

int remove_weapon_from_limb(object ob) {
  int i;
  string *ind;

  ind = keys(wielded);
  for(i=0; i<sizeof(ind); i++) {
    if(wielded[ind[i]] == ob) {
      map_delete(wielded, ind[i]);
      if(body[ind[i]]) {
        body[ind[i]]["armour"] -= ({ "weapon" });
        body[ind[i]]["armour_ob"] -= ({ ob });
        body[ind[i]]["weapons"] = 0;
      } else CHAT_D->do_raw_chat("system", "Error <system> Error occured in remove_weapon_from_limb() in body.c:  "+file_name(this_object()));
    }
  }
  num_wielded --;
  return 1;
}

int remove_armour_from_limb(object arm, string *limb) {
  int i, arm_class;
  string type;

  arm_class = (int)arm->query_ac();
  type = (string)arm->query_type();
  for(i=0; i<sizeof(limb); i++) {
    if(!body) continue;
    if(!body[limb[i]]) continue;
    if(member_array(type, body[limb[i]]["armour"]) != -1) {
      if(member_array(type, body[limb[i]]["armour"]) == 0)
        body[limb[i]]["armour"] = body[limb[i]]["armour"][1..sizeof(body[limb[i]]["armour"])-1];
      else if(member_array(type, body[limb[i]]["armour"]) == sizeof(body[limb[i]]["armour"])-1)
        body[limb[i]]["armour"] = body[limb[i]]["armour"][0..sizeof(body[limb[i]]["armour"])-2];
      else
        body[limb[i]]["armour"] = body[limb[i]]["armour"][0..member_array(type, body[limb[i]]["armour"])-1] + body[limb[i]]["armour"][member_array(type, body[limb[i]]["armour"])+1..sizeof(body[limb[i]]["armour"])-1];
    }
    body[limb[i]]["ac"] -= arm_class;
    body[limb[i]]["armour_ob"] -= ({ arm });
  }
  return 1;
}

void set_fingers(int x) {
  all_my_fingers = x;
}

int query_fingers() { return all_my_fingers; }

void set_wielding_limbs( string *str) {
  int i;

  for(i=0; i<sizeof(str); i++) {
    if(member_array(str[i], limbs) == -1) continue;
    body[str[i]]["wieldable"] = 1;
  }
}

void add_wielding_limb(string str) {
  if(member_array(str, limbs) == -1) return;
  body[str]["wieldable"] = 1;
}

string *query_wielding_limbs() {
  string *tmp;
  int i;
  tmp = ({});

  for(i=0; i<sizeof(limbs); i++) {
    if(body[limbs[i]]["wieldable"]) 
      tmp += ({ limbs[i] });
  }
  return tmp;
}

void fix_limbs() {
  int i;

  for(i=0; i<sizeof(limbs); i++) {
    body[limbs[i]]["armour"] = ({});
    body[limbs[i]]["armour_ob"] = ({});
    body[limbs[i]]["ac"] = 0;
    body[limbs[i]]["weapon"] = 0;
  }
  wielded = ([]);
}

string *query_severed_limbs() {
  if(!severed) return ({});
  else return keys(severed);
}
string *query_limbs_wielded() { return (wielded ? keys(wielded) : ({})); }
object *query_wielded() { return (wielded ? values(wielded) : ({})); }
object *query_wielded_unique() {
  return map(
   unique_array(query_wielded(), (: file_name($1) :) ),
   (: arrayp($1) ? $1[0] : $1 :)
  );
}

object query_weapon(string limb) {
  if(!wielded) return 0;
  if(!wielded[limb]) return 0;
  return wielded[limb];
}

//  initialize the variables

void init_complex_body() {
  target_limb = "";
}

void heal_limb(string str, int x) {
  if(member_array(str, limbs) == -1) return;
  if(!body[str]) return;
  body[str]["damage"] -= x;
  if(body[str]["damage"] < 0) body[str]["damage"] = 0;
}

int severed_limb(string limb) {
  //  int temp;
  string childlimb;

  if(!body[limb]) return 0;
  childlimb = body[limb]["limb_ref"];
  if(childlimb == "FATAL") {
    this_object()->set_hp(-100);
    return 2;
  }
  if(childlimb == "") {
    remove_limb(limb);
    return 1;
  }
  if(!body[childlimb]) {
    remove_limb(limb);
    return 1;
  }
  /*  why the hell was this here? -wiz Sun Feb 24 23:58:44 HST 2002
      temp = body[childlimb]["damage"];
      if(temp < body[childlimb]["max_dam"]) {
          do_damage(childlimb, 100);
          check_on_limb(childlimb);
      }
      just remove it.
  */
  remove_limb(childlimb);
  remove_limb(limb);
  return 1;
}

int check_on_limb(string limb) {
  object weap;
  object *arm;
  //    string *locations;
  int i;

  object old_limb;

  if(!body[limb]) return 0;
  if(body[limb]["damage"] > body[limb]["max_dam"]) {
    if(wizardp(this_object()) && !this_object()->query_killable()) {
      message("my_combat", sprintf("If you were not immortal, you would "
        "lose your %s right now!", limb), this_object());
      body[limb]["damage"] = 0;
      return 1;
    }
    if((limb == "torso") || (limb == "head"))
      message("my_combat", "A mortal blow is dealt to your body!", this_object());
    else message("my_combat", sprintf("Your %s is severed!",limb),
       this_object());
    if(limb == "torso") tell_object(environment(this_object()),this_object()->query_cap_name()+" is dealt a mortal blow to the "+limb+"!", this_object());
    else tell_room(environment(this_object()),this_object()->query_cap_name()+" has "+this_object()->query_possessive()+" "+limb+" severed!", this_object());
    weap = wielded[limb];
    if (!weap) weap=wielded[body[limb]["limb_ref"]];
    if(weap) {
      remove_weapon_from_limb(weap);
      weap->set_not_equipped();
    }
    arm = body[limb]["armour_ob"];
    if(sizeof(arm)) {
      for(i = 0; i<sizeof(arm); i++) {
        if (arm[i]) {
          remove_armour_from_limb(arm[i], (string *)arm[i]->query_actual_limbs());
          arm[i]->set_not_equipped();
        }
      }
    }
    old_limb = new(OB_BODY_PART);
    old_limb->set_limb(query_cap_name(), limb);
    old_limb->move(environment(this_object()));
    if(weap) weap->move(old_limb);
    if(arm) {
      for(i=0; i<sizeof(arm); i++) {
        arm[i]->move(old_limb);
      }
    }
    if ((i = severed_limb(limb)) != 2) {
      this_object()->add_hp(-(60+random(15)));
      //this_object()->add_heal_rate_bonus("hp", -5);
      this_object()->add_bleeding(25+random(15));
    }
    return i;
  }
  return 1;
}


void add_death(string str) {
  if(!str) return;
  if(!deaths) deaths = ({ ({str, time()}) });
  else deaths += ({ ({ str, time() }) });
}
mixed *query_deaths() { return deaths; }



void set_target_limb(string str) {
  if(!stringp(str)) return;
  if(member_array(str, limbs) == -1) return;
  target_limb = str;
}
