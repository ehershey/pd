//      /std/armour.c
//      from the Nightmare Mudlib
//      the basic inherited armour object
//      created by Descartes of Borg 25 june 1993

#include <std.h>
#include <security.h>
#include <function.h>

inherit OBJECT;
inherit RESISTANCES;


private static string *ARMOUR_TYPES = ({
  "helmet", "mask", "body armour", "armour", "cloak", 
  "saddle", "blanket", "shield", "robes", "ring",
  "belt", "pants", "boots", "leggings", "tunic",
  "bracelet", "necklace", "vest", "bracers", "gloves",
  "halo", "badge", "quiver", "backpack", "earrings",
  "wing armour", "chainmail", "shirt", "dress", "sash",
  "hat", "garter", "cape", "clasp", "coat",
  "collar", "amulet",
});

private static string *RING_LIMBS = ({
  "left hand", "right hand",
  "left paw", "right paw",
  "first hand", "second hand", 
  "third hand", "fourth hand",
  "left front claw", "right front claw",
});

private mapping __Armour;
private static int theft=0, fingers=0;


void set_wc(int x);
int query_wc();
void set_ac(int x);
int query_ac();
void set_ac_bonus(int x);
void add_ac_bonus(int x);
int query_ac_bonus();
int query_base_ac();
int query_original_ac();
void set_type(string str);
string query_type();
void set_limbs(string *l);
string *query_limbs();
string *query_worn_limbs();
string *query_actual_limbs();
mixed query_hit();
mixed do_hit(object tgt);
mixed query_wear();
mixed query_remove();
mixed query_unwear();
string query_wear_string();
mixed query_wear_func();
string query_remove_string();
mixed query_remove_func();
void set_wear(mixed val);
void set_remove(mixed val);
void set_unwear(mixed val);
mixed query_post_wear_func();
void set_post_wear_func(mixed f);
mixed query_post_remove_func();
void set_post_remove_func(mixed f);
object query_worn();
void silent_unequip();
void set_not_equipped();
void set_ac_penalty(int x);
int query_ac_penalty();
string query_long_more();
string query_short_more();
string query_long_fingers();
string query_long_worn();
string query_short_more();
string query_long_fingers();
string query_long_worn();
string query_short_worn();
int is_armour();
void set_theft(int i);
int query_theft();
void set_decay_rate(int x);
int query_decay_rate();
void decay();
void force_decay();
int query_fingers();
void set_fingers(int x);
int query_can_equip(string *limbs);
string query_ring_limb(object tp);
varargs string equip(object tp, string *limbs, int force, int penalty);
varargs void unequip(int force);


void create() {
  object::create();
  resistances::create();
  __Armour = ([]);
  __Armour["type"] = 0;
  __Armour["limbs"] = 0;
  __Armour["fingers"] = 0;
  __Armour["worn"] = 0;
  __Armour["worn limbs"] = 0;
  __Armour["ac"] = 0;
  __Armour["wc"] = 0;
  __Armour["original ac"] = 0;
  __Armour["ac bonus"] = 0;
  __Armour["ac penalty"] = 0;
  __Armour["hit"] = 0;
  __Armour["wear"] = 0;
  __Armour["remove"] = 0;
  __Armour["decay rate"] = 0;
  __Armour["decay status"] = 0;
  __Armour["post wear func"] = 0;
  __Armour["post remove func"] = 0;
}

void set_wc(int x) { __Armour["wc"] = x; }
int query_wc() { return __Armour["wc"]; }
 
void set_ac(int x) {
  if (x > 20) {
    log_file("illegal", file_name(this_object())+": euid ("+
      geteuid(this_object())+") has an ac of "+x+"\n"
    );
  }

  if (!__Armour["decay rate"])
    __Armour["decay rate"] = 10000/(x+2);

  __Armour["ac"] = x;
  
  if (!__Armour["original ac"])
    __Armour["original ac"] = x;
}
int query_ac() {
  return query_base_ac() + query_ac_bonus();
}
void set_ac_bonus(int x) { __Armour["ac bonus"] = x; }
void add_ac_bonus(int x) { set_ac_bonus(query_ac_bonus() + x); }
int query_ac_bonus() { return __Armour["ac bonus"]; }
int query_base_ac() { return __Armour["ac"]; }
int query_original_ac() { return __Armour["original ac"]; }
 
void set_type(string str) { __Armour["type"] = str; }
string query_type() { return __Armour["type"]; }

void set_limbs(string *l) { __Armour["limbs"] = l; }
string *query_limbs() {
  if (__Armour["type"] == "ring") {
  }
  return __Armour["limbs"];
}

string *query_worn_limbs() { return __Armour["worn limbs"]; }
string *query_actual_limbs() { return query_worn_limbs(); }

void set_hit(mixed val) {
  if (functionp(val) && !(functionp(val) & FP_LOCAL || functionp(val) & FP_NOT_BINDABLE)) {
    function f = bind(val, this_object());
    if (functionp(f)) val = f;
  }
  __Armour["hit"] = val; 
}
mixed query_hit() { return __Armour["hit"]; }
mixed do_hit(object tgt) {
  mixed ret = query_hit();
  if (functionp(ret))
    ret = to_int(evaluate(ret, tgt));
  if (!intp(ret) && !stringp(ret)) ret = 0;
  return ret;
}
 
mixed query_wear() { return __Armour["wear"]; }
mixed query_remove() { return __Armour["remove"]; }
mixed query_unwear() { return query_remove(); }

string query_wear_string() {
  if (stringp(__Armour["wear"]))
    return __Armour["wear"];
  return 0;
}
mixed query_wear_func() {
  if (functionp(__Armour["wear"]))
    return __Armour["wear"];
  return 0;
}
 
string query_remove_string() {
  if (stringp(__Armour["remove"]))
    return __Armour["remove"];
  return 0;
}
mixed query_remove_func() {
  if (functionp(__Armour["remove"]))
    return __Armour["remove"];
  return 0;
}
 
void set_wear(mixed val) { __Armour["wear"] = val; }
void set_remove(mixed val) { __Armour["remove"] = val; }
void set_unwear(mixed val) { set_remove(val); }

mixed query_post_wear_func() { return __Armour["post wear func"]; }
void set_post_wear_func(mixed f) { __Armour["post wear func"] = f; }

mixed query_post_remove_func() { return __Armour["post remove func"]; }
void set_post_remove_func(mixed f) { __Armour["post remove func"] = f; }

object query_worn() { return __Armour["worn"]; }
 
void silent_unequip() {
  set_theft(1);
  unequip();
  set_theft(0);
}

void set_not_equipped() {
  set_theft(1);
  unequip(1);
  set_theft(0);
}
 
// this is a penalty based on conditions at wear time and is
// removed when armour is, currently not used
void set_ac_penalty(int x) { __Armour["ac penalty"] = x; }
int query_ac_penalty() { return __Armour["ac penalty"]; }
 
string query_long_more() {
  string ret = "";
  foreach (string long in ({ "fingers", "worn" })) {
    string tmp = call_other(this_object(), "query_long_"+long);
    if (tmp)
      ret += tmp + "\n";
  }
  if (strlen(ret))
    return ret[0..<1];
  return 0;
}
string query_short_more() {
  return query_short_worn();
}
string query_long_fingers() {
  if (query_fingers())
    return "There are "+cardinal(query_fingers())+
      " finger holes.";
  else return 0;
}
string query_long_worn() {
  if (query_worn()) return "Worn on: "+list(query_actual_limbs())+".";
  else return 0;
}
string query_short_worn() {
  if (query_worn()) return " (worn)";
  else return "";
}
 
int is_armour() { return 1; }
 
void set_theft(int i) { theft = i; }
int query_theft() { return theft; }

void set_decay_rate(int x) { __Armour["decay rate"] = x; }
int query_decay_rate() { return __Armour["decay rate"]; }
 
void decay() {
  if (!query_decay_rate()) return;
  if (!__Armour["ac"]) return;
  __Armour["decay status"]++;
  if (__Armour["decay status"] == __Armour["decay rate"])
    force_decay();
}

void force_decay() {
  if (!__Armour["ac"]) return;
  __Armour["ac"]--;
  set("value",1+query("value")*__Armour["ac"]/__Armour["original ac"]);
  message("environment", "You notice some wear on your "+
    query_short()+".", __Armour["worn"]);
  __Armour["decay_status"] = 0;
}

int query_fingers() { return fingers; }
void set_fingers(int x) { fingers = x; }

// this function is only used to check if a set of limbs passed to the wear
// command is valid, example: <wear vest on left arm and right arm>
// checks query_can_equip( ({ "left arm", "right arm" }) )
int query_can_equip(string *limbs) {
  // rings can be worn on any of the limbs in RING_LIMBS
  if (__Armour["type"] == "ring" && sizeof(limbs) == 1 &&
      member_array(limbs[0], RING_LIMBS) != -1)
        return 1;
  // if all of query_limbs() is also in the limbs var
  if (sizeof(query_limbs() & limbs) >= sizeof(query_limbs()))
    return 1;
  return 0;
}

string query_ring_limb(object tp) {
  if (!tp) return 0;
  foreach (string limb in RING_LIMBS)
    if (tp->type_ok("ring", limb) == 0)
      return limb;
  return 0;
}

varargs string equip(object tp, string *limbs, int force, int penalty) {
  string error;
  mixed wear = query_wear();
  mixed post;

  if (nullp(tp))
    return "Wearer not specified.";
  
  if (!query_type() || member_array(query_type(), ARMOUR_TYPES) == -1)
    return "This armour ("+query_short()+") has an invalid type.";

  if (query_type() == "ring" && !sizeof(limbs)) {
    limbs = ({ query_ring_limb(tp) });
    if (!limbs[0])
      return "You cannot wear any more rings.";
  }

  else if (nullp(limbs) || !sizeof(limbs))
    return "Limbs not specified.";

  if (!force) {
    if (functionp(wear) && !evaluate(wear))
      return "You are unable to wear "+remove_article(strip_color(query_short()))+".";
  }

  error = tp->equip_armour_to_limb(this_object(), limbs);
  if (error)
    return error;

  if (stringp(wear))
    message("my_action", wear, tp);
  else
    message("my_action", "You wear "+remove_article(query_short())+".", tp);
  
  if (environment(tp))
    message("other_action", tp->query_cap_name()+" wears "+
      remove_article(query_short())+".",
      environment(tp), tp);

  if (penalty && !query_ac_penalty()) {
    set_ac_penalty(penalty);
    add_ac_bonus(-penalty);
  }

  __Armour["worn"] = tp;
  __Armour["worn limbs"] = limbs;

  post = __Armour["post wear func"];
  if (functionp(post) && !(functionp(post) & FP_OWNER_DESTED))
    evaluate(post, tp);

  return 0;
}

varargs void unequip(int force) {
  object tp = __Armour["worn"];
  mixed remove = query_remove();
  mixed post;

  if (!tp && !force) return;

  if (!force) {
    if (functionp(remove) && !evaluate(remove))
      return;
  }
  
  if (tp) {
    if (!query_theft()) {
      if (stringp(remove))
        message("my_action", remove, tp);
      else
        message("my_action", "You remove "+
          remove_article(query_short())+".", tp);
      if (environment(tp))
        message("other_action", tp->query_cap_name() +
          " removes "+remove_article(query_short())+".",
          environment(tp), tp);
    }
    tp->remove_armour_from_limb(this_object(), __Armour["worn limbs"]);
  }

  if (query_ac_penalty()) {
    add_ac_bonus(query_ac_penalty());
    set_ac_penalty(0);
  }
  __Armour["worn"] = 0;
  __Armour["worn limbs"] = 0;

  post = __Armour["post remove func"];
  if (functionp(post) && !(functionp(post) & FP_OWNER_DESTED))
    evaluate(post, tp);
}

