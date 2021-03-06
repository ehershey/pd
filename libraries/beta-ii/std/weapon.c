#include <std.h>
#include <function.h>
#include <damage_types.h>
#include <damage.h>

inherit OBJECT;
inherit RESISTANCES;
 
private mapping __Weapon;
private static int theft=0;

// damage types the weapon will inflict during idle hits
// this does not count ammo like arrows, only the weapon itself
// array == choose one at random for each hit
private static mapping DEFAULT_DAMAGE_TYPES = ([
  "axe" : DAMAGE_PHYSICAL | DAMAGE_SLASH | DAMAGE_IMPACT,
  "blade" : ({
    DAMAGE_PHYSICAL | DAMAGE_SLASH,
    DAMAGE_PHYSICAL | DAMAGE_SLASH,
    DAMAGE_PHYSICAL | DAMAGE_PIERCE,
  }),
  "blunt" : DAMAGE_PHYSICAL | DAMAGE_IMPACT,
  "knife" : ({
    DAMAGE_PHYSICAL | DAMAGE_PIERCE,
    DAMAGE_PHYSICAL | DAMAGE_PIERCE,
    DAMAGE_PHYSICAL | DAMAGE_SLASH,
  }),
  "flail" : DAMAGE_PHYSICAL | DAMAGE_SLASH | DAMAGE_IMPACT,
  "projectile" : DAMAGE_PHYSICAL | DAMAGE_PIERCE,
  "ranged" : DAMAGE_PHYSICAL | DAMAGE_IMPACT,
]);

// flags that apply to idle rounds
private static mapping DEFAULT_DAMAGE_FLAGS = ([
  "knife" : DAMAGE_NO_SEVER,
  "flail" : DAMAGE_NO_SEVER | DAMAGE_HP_ONLY,
  "projectile" : DAMAGE_NO_SEVER,
  "ranged" : DAMAGE_NO_SEVER,
]);
 
object query_wielded();
void set_ac(int x);
int query_ac();
void set_wc(int x);
void set_wc_bonus(int x);
void add_wc_bonus(int x);
int query_wc();
int query_base_wc();
int query_wc_bonus();
int query_original_wc();
void set_type(string str);
string query_type();
void set_skill_level(int x);
int query_skill_level();
void set_damage_type(mixed dtype);
varargs mixed query_damage_type(int dtype);
void set_damage_flags(int flags);
int query_damage_flags();
void set_hit(mixed val);
mixed query_hit();
mixed do_hit(object);
void set_wield(mixed val);
mixed query_wield();
void set_unwield(mixed val);
mixed query_unwield();
void set_post_wield_func(mixed f);
mixed query_post_wield_func();
void set_post_unwield_func(mixed f);
mixed query_post_unwield_func();
void set_hands(int x);
int query_hands();
void add_poisoning(int x);
int query_poisoning();
void set_theft(int x);
int query_theft();
void set_decay_rate(int x);
int query_decay_rate();
void decay();
void force_decay();
int is_weapon();
varargs void unequip(int);
varargs string equip(object, string *, int);
void silent_unequip();
void set_not_equipped();
void set_wc_penalty(int x);
int query_wc_penalty();

void create() {
  object::create();
  resistances::create();
  set_long_more( ({ "query_long_wielded" }) );
  set_short_more( ({ "query_short_wielded" }) );
  __Weapon = ([]);
  __Weapon["type"] = 0;
  __Weapon["wielded"] = 0;
  __Weapon["wielded limbs"] = 0;
  __Weapon["hands"] = 1;
  __Weapon["skill level"] = 0;
  __Weapon["wc"] = 0;
  __Weapon["original wc"] = 0;
  __Weapon["wc bonus"] = 0;
  __Weapon["wc penalty"] = 0;
  __Weapon["damage type"] = 0;
  __Weapon["damage flags"] = 0;
  __Weapon["hit"] = 0;
  __Weapon["wield"] = 0;
  __Weapon["unwield"] = 0;
  __Weapon["poison"] = 0;
  __Weapon["decay rate"] = 0;
  __Weapon["decay status"] = 0;
}

void set_ac(int x) { __Weapon["ac"] = x; }
int query_ac() { return __Weapon["ac"]; }
 
void set_wc(int x) {
  if (x > 20) {
    log_file("illegal", file_name(this_object())+": euid ("+
      geteuid(this_object())+") has a wc of "+x+"\n"
    );
  }

  if (!__Weapon["decay rate"])
    __Weapon["decay rate"] = 10000/(x+1);

  __Weapon["wc"] = x;
  
  if (!__Weapon["original wc"])
    __Weapon["original wc"] = x;

  switch (x) {
    case 0..5:
      set_skill_level(x-1);
    break;

    case 6..10:
      set_skill_level(x*8 - 10);
    break;

    default:
      set_skill_level(x*15 - 80);
    break;
  }
}
int query_wc() {
  return query_base_wc() + query_wc_bonus() +
         query_property("enchantment");
}
void set_wc_bonus(int x) { __Weapon["wc bonus"] = x; }
void add_wc_bonus(int x) { set_wc_bonus(query_wc_bonus() + x); }
int query_wc_bonus() { return __Weapon["wc bonus"]; }
int query_base_wc() { return __Weapon["wc"]; }
int query_original_wc() { return __Weapon["original wc"]; }
 
void set_type(string str) {
  __Weapon["type"] = str;
  set_damage_type(DEFAULT_DAMAGE_TYPES[str]);
  set_damage_flags(DEFAULT_DAMAGE_FLAGS[str]);
}
string query_type() { return __Weapon["type"]; }
 
void set_skill_level(int x) { __Weapon["skill level"] = (x < 0 ? 0 : x); }
int query_skill_level() { return __Weapon["skill level"]; }

// this can be an int or an array of ints
void set_damage_type(mixed dtype) {

  if (intp(dtype) || (arrayp(dtype) && sizeof(dtype) && intp(dtype[0])) )
    __Weapon["damage type"] = dtype;
}
// query_damage_type(DAMAGE_SLASH) will return 1 if this weapon can
// do that kind of damage, 0 if not
// query_damage_type() will return either a single damage type or an
// array of possible damage types
varargs mixed query_damage_type(int dtype) {
  mixed tmp = copy(__Weapon["damage type"]);
  if (!arrayp(tmp))
    tmp = ({ tmp });
  if (nullp(dtype))
    return tmp[random(sizeof(tmp))];
  foreach (int t in tmp)
    if (t & dtype)
      return 1;
  return 0;
}

void set_damage_flags(int flags) { __Weapon["damage flags"] = flags; }
int query_damage_flags() { return __Weapon["damage flags"]; }
 
void set_hands(int x) { __Weapon["hands"] = (x < 1 ? 1 : x); }
int query_hands() { return __Weapon["hands"]; }

void set_hit(mixed val) {
  if (functionp(val) && !(functionp(val) & FP_LOCAL || functionp(val) & FP_NOT_BINDABLE)) {
    function f = bind(val, this_object());
    if (functionp(f)) val = f;
  }
  __Weapon["hit"] = val; 
}
mixed query_hit() { return __Weapon["hit"]; }
mixed do_hit(object tgt) {
  mixed ret = query_hit();
  if (functionp(ret))
    ret = to_int(evaluate(ret, tgt));
  if (!intp(ret) && !stringp(ret)) ret = 0;
  return ret;
}
 
mixed query_wield() { return __Weapon["wield"]; }
mixed query_unwield() { return __Weapon["unwield"]; }
 
void set_wield(mixed val) { __Weapon["wield"] = val; }
void set_unwield(mixed val) { __Weapon["unwield"] = val; }

object query_wielded() { return __Weapon["wielded"]; }

void set_post_wield_func(mixed f) { __Weapon["post wield func"] = f; }
mixed query_post_wield_func() { return __Weapon["post wield func"]; }
void set_post_unwield_func(mixed f) { __Weapon["post unwield func"] = f; }
mixed query_post_unwield_func() { return __Weapon["post unwield func"]; }
 
varargs string equip(object tp, string *limbs, int force, int penalty) {
  string error;
  mixed wield = query_wield();
  mixed post;

  if (nullp(tp) || nullp(limbs) || !sizeof(limbs))
    return "Wielder or limbs not specified.";

  if (!force) {
    if (functionp(wield) && !evaluate(wield))
      return "You are unable to wield "+definite_article(query_short())+".";
  }

  error = tp->equip_weapon_to_limb(this_object(), limbs);
  if (error)
    return error;

  if (stringp(wield))
    message("my_action", wield, tp);
  else
    message("my_action", "You wield "+definite_article(query_short())+".", tp);
  
  if (environment(tp))
    message("other_action", tp->query_cap_name()+" wields "+
      definite_article(query_short())+".",
      environment(tp), tp);

  if (penalty && !query_wc_penalty()) {
    set_wc_penalty(penalty);
    add_wc_bonus(-penalty);
  }

  __Weapon["wielded"] = tp;
  __Weapon["wielded limbs"] = limbs;
  
  post = __Weapon["post wield func"];
  if (functionp(post) && !(functionp(post) & FP_OWNER_DESTED))
    evaluate(post, tp);
  
  return 0;
}

varargs void unequip(int force) {
  object tp = __Weapon["wielded"];
  mixed unwield = query_unwield();
  mixed post;

  if (!tp && !force) return;

  if (!force) {
    if (functionp(unwield) && !evaluate(unwield))
      return;
  }
  
  if (tp) {
    if (!query_theft()) {
      if (stringp(unwield))
        message("my_action", unwield, tp);
      else
        message("my_action", "You unwield "+
          definite_article(query_short())+".", tp);
      if (environment(tp))
        message("other_action", tp->query_cap_name() +
          " unwields "+definite_article(query_short())+".",
          environment(tp), tp);
    }
    tp->remove_weapon_from_limb(this_object());
  }

  if (query_wc_penalty()) {
    add_wc_bonus(query_wc_penalty());
    set_wc_penalty(0);
  }
  __Weapon["wielded"] = 0;
  __Weapon["wielded limbs"] = 0;

  post = __Weapon["post unwield func"];
  if (functionp(post) && !(functionp(post) & FP_OWNER_DESTED))
    evaluate(post, tp);
  
}

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
 
// this is a penalty based on conditions at wield time and is
// removed at unwield, currently used only for warrior special
// ability to use one less hand for wielding
void set_wc_penalty(int x) { __Weapon["wc penalty"] = x; }
int query_wc_penalty() { return __Weapon["wc penalty"]; }
 
void add_poisoning(int x) {
  if (!__Weapon["poison"]) __Weapon["poison"] = x;
  else __Weapon["poison"] += x;
  if (__Weapon["poison"] < 1) __Weapon["poison"] = 0;
}
int query_poisoning() { return __Weapon["poison"]; }
 
string query_short_wielded() {
  if (query_wielded())
    return " (wielded)";
  return "";
}

string query_long_wielded() {
  if (query_wielded())
    return "It is wielded in your "+list(__Weapon["wielded limbs"])+".";
  return "";
}
 
int is_weapon() { return 1; }
 
void set_decay_rate(int x) { __Weapon["decay rate"] = x; }
int query_decay_rate() { return __Weapon["decay rate"]; }
 
void decay() {
  if (!query_decay_rate()) return;
  if (!__Weapon["wc"]) return;
  __Weapon["decay status"]++;
  if (__Weapon["decay status"] == __Weapon["decay rate"])
    force_decay();
}

void force_decay() {
  if (!__Weapon["wc"]) return;
  __Weapon["wc"]--;
  set("value",1+query("value")*__Weapon["wc"]/__Weapon["original wc"]);
  message("environment", "You notice some wear on your "+query_short()+".",
    __Weapon["wielded"]);
  __Weapon["decay_status"] = 0;
}

void set_theft(int x) { theft = x; }
int query_theft() { return theft; }
