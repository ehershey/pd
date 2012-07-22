//      /std/armour.c
//      from the Nightmare Mudlib
//      the basic inherited armour object
//      created by Descartes of Borg 25 june 1993
//      fixed up by Nulvect 2007-02-24

#include <std.h>
#include <security.h>

#define ARMOUR_TYPES ({\
  "helmet", "mask", "body armour", "armour", "cloak",\
  "saddle", "blanket", "shield", "robes", "ring", "belt",\
  "pants", "boots", "leggings", "tunic", "bracelet",\
  "necklace", "vest", "bracers", "gloves", "halo", "badge",\
  "quiver", "backpack", "earrings", "wing armour", "chainmail",\
  "shirt", "dress", "sash", "hat", "garter", "cape", "clasp",\
  "coat", "collar", "amulet"\
})

inherit OBJECT;

private mapping armour_save;
private static mapping armour_static;
private static int theft=0, fingers=0;

int equip(object tp, string *limbs);
int unwear();
int unequip();
void set_not_equipped();
void set_ac(int x);
int query_ac();
int query_original_ac();
void set_base_ac(int x);
int query_base_ac();
void set_theft(int i);
int query_theft();
void set_wear(mixed val);
mixed query_wear();
void set_unwear(mixed val);
mixed query_unwear();
void set_remove(mixed val);
mixed query_remove();
void set_type(string str);
string query_type();
void set_limbs(string *borg);
string *query_limbs();
void set_worn(object who);
object query_worn();
void set_actual_limbs(string *limbs);
string *query_actual_limbs();
void set_fingers(int x);
int query_fingers();
string query_ring_limb(object tp);
void set_struck(mixed val);
mixed query_struck();
void force_decay();
string query_short_worn();
string query_short_more();
string query_long_worn();
string query_long_more();
int is_armour();

void create() {
    ::create();
    armour_save = ([]);
    armour_static = ([]);
}

// equip/unequip functions

int equip() {
  object tp=environment(this_object());
  string *limbs;
  string ret;
  mixed wear;

  if (!tp || query_worn())
    return 0;

  if (!query_type() || member_array(query_type(), ARMOUR_TYPES) == -1) {
    message("info", "This piece of armour is bugged. It has been reported.", tp);
    return 0;
  }

  wear = query_wear();
  if (functionp(wear) && !((*wear)()) ) return 0;

  if (query_type() == "ring")
    set_limbs( ({ query_ring_limb(tp) }) );

  limbs = query_limbs();

  ret = tp->equip_armour_to_limb(this_object(), limbs);
  if (stringp(ret)) {
    if (ret != "NO")
      message("my_action", ret, tp);
    return 0;
  }

  if (stringp(wear))
    message("my_action", wear, tp);
  else
    message("my_action", "You wear "+query_short()+".", tp);
  message("other_action", tp->query_cap_name()+" wears "+
    tp->query_possessive()+" "+query_short()+".", environment(tp), tp);

  set_worn(tp);
  set_actual_limbs(limbs);
  
  return 1;
}

int unwear() {
  object tp = query_worn();
  mixed unw = query_unwear();
    
  if (functionp(unw) && !((*unw)()) ) return 0;
  
  else if (!query_theft()) {

    if (stringp(unw))
      message("my_action", unw, tp);
  
    else
      message("my_action", "You remove your "+query_short()+".", tp);
    
    if (environment(tp))
      message("other_action", tp->query_cap_name()+" removes "+
        tp->query_possessive()+" "+query_short()+".", environment(tp), tp);

  }

  tp->remove_armour_from_limb(this_object(), query_actual_limbs());

  set_not_equipped();

  return 1;
}
 
int unequip() {
  if (query_worn()) return unwear();
  else return 0;
}
 
void set_not_equipped() {
  set_worn(0);
  set_actual_limbs(({}));
}

// ---

 
// ac

void set_ac(int x) {
  armour_save["ac"] = x;
  if (!armour_save["original ac"])
    armour_save["original ac"] = x;
}
 
int query_ac() { return armour_save["ac"] + query_property("enchantment"); }

int query_base_ac() { return armour_save["ac"]; }

int query_original_ac() { return armour_save["original ac"]; }

// ---


// wear/unwear functions and strings

void set_wear(mixed val) {
  armour_static["wear"] = val;
}

void set_unwear(mixed val) {
  armour_static["unwear"] = val;
}
void set_remove(mixed val) {
  set_unwear(val);
}

mixed query_wear() { return armour_static["wear"]; }
 
mixed query_unwear() { return armour_static["unwear"]; }

mixed query_remove() { return query_unwear(); }


// ---


// descriptions
 
string query_short_worn() {
  if (query_worn()) return " (worn)";
  else return "";
}
string query_short_more() { return query_short_worn(); }
 
string query_long_worn() {
  string *l = query_actual_limbs();
  if (sizeof(l))
    return "Worn on: "+implode(l, ", ");
  else
    return "";
}
string query_long_more() { return query_long_worn(); }

// ---


// limbs

int query_fingers() { return fingers; }

void set_fingers(int x) { fingers = x; }

void set_limbs(string *borg) { armour_save["possible limbs"] = borg; }

string *query_limbs() { return armour_save["possible limbs"]; }

void set_actual_limbs(string *limbs) { armour_static["actual limbs"] = limbs; }

string *query_actual_limbs() { return armour_static["actual limbs"]; }

void set_type(string str) {
  armour_save["type"] = str;
  if (member_array(str, ARMOUR_TYPES) == -1) {
    seteuid(UID_LOG);
    if (clonep(this_object()))
      log_file("balarm", base_name(this_object())+" set_type() out of bounds.\n");
    seteuid(geteuid());
  }
}

string query_type() { return armour_save["type"]; }

void set_worn(object who) { armour_static["worn by"] = who; }

object query_worn() { return armour_static["worn by"]; }

string query_ring_limb(object tp) {
  int fing;
  string *hands;
  mapping races = ([
    "dragon" : ({"front left claw", "front right claw"}),
    "bastet" : ({"left paw", "right paw"}),
    "raknid" : ({"first hand", "second hand",
                 "third hand", "fourth hand"}),
    "default" : ({"left hand", "right hand"}),
  ]);
  
  if (!tp) return "left hand";

  fing = tp->query_fingers();
  if (member_array(tp->query_race(), keys(races)) == -1)
    hands = races["default"];
  else
    hands = races[tp->query_race()];
  
  foreach (string h in hands) {
    object *rings = tp->query_armour(h);
    rings = filter(rings, (: $1->query_type() == "ring" :) );
    if (sizeof(rings) < fing)
      return h;
  }

  // if it gets here, there are no free fingers,
  // equip_armour_to_limb() in body.c will return
  // an error that will be sent to the player
  return hands[0];
}

// ---


// misc
 
int is_armour() { return 1; }
 
// what the hell are these for??
void set_struck(mixed val) {
    if(functionp(val) && geteuid(this_object()) != geteuid(val[0])) return;
    armour_static["struck"] = val;
}
mixed query_struck() { return armour_static["struck"]; }
//

void set_theft(int i) { theft = i; }

int query_theft() { return theft; }

void force_decay()
{
    if(!query_base_ac()) return;
    set_ac(query_base_ac()-1);
    if (query_worn())
      message("environment", "You notice some wear on your "+
        query_short()+".", query_worn());
}

// ---

