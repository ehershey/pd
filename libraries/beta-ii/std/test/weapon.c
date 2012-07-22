#include <config.h>
#include <teststd.h>

#define ELEMENTS ({ "fire", "earth", "ice" })

inherit OBJECT;
 
private mapping __Weapon;
private static int theft=0, orig_wc;
 
int __Wield(string str);
int __Unwield(string str);
object query_wielded();
void set_ac(int x);
void set_wc(int x);
void set_hit(mixed val);
void set_wield(mixed val);
void set_unwield(mixed val);
void set_type(string str);
void set_theft(int x);
void set_hands(int x);
void set_decay_rate(int x);
void add_poisoning(int x);
int sharpen(int x);
int query_ac();
int query_theft();
int query_wc();
mixed query_hit();
mixed query_wield();
mixed query_unwield();
string query_type();
int query_decay_rate();
int query_poisoning();
int is_weapon();
void unequip();
void __ActuallyUnwield();
void set_not_equipped();
void decay();
void set_element(string elem, int x);
string query_element();
int query_element_amnt();

void create() {
    ::create();
    __Weapon = ([]);
    __Weapon["hands"] = 1;
}
 
void init() {
    ::init();
    if(environment(this_object()) != this_player()) return;
    add_action("__Wield", "wield");
    add_action("__Unwield", "unwield");
}

int query_hands() { return __Weapon["hands"]; }

void set_element(string elem, int x) {
    if(member_array(elem, ELEMENTS) == -1)
        return;
    if(x > 50)
        x = 50;
    if(x < 1)
        x = 0;
    __Weapon["Element"] = elem;
    __Weapon["ElemSize"] = x;
}

string query_element() {
    if(__Weapon["Element"])
        return __Weapon["Element"];
    return "unknown";
}

int query_element_amnt() {
    if(__Weapon["ElemSize"])
        return __Weapon["ElemSize"];
    return 0;
}
 
int __Wield(string str) {
    string what, where, ok;
    string *tryhands;
    int hands;
    int war, lower;
    int ench;

    if (this_player()->query_race() == "dragon" ||
        this_player()->query("bear") ||
        this_player()->query("lion") ||
        this_player()->query("wolf")) {
          write("Your claws would work much better than that!");
          return 1;
    }

    if (!str) return notify_fail("Wield what?\n");

    // allow skilled warriors to use 1 less hand for multi-handed weapons
    // weapons wielded this way will incur a WC penalty for balance
    if (this_player()->query_subclass() == "warrior" &&
        this_player()->query_skill("double wielding") >= 120)
      war=1;

    if (sscanf(str, "%s in %s", what, where) == 2) {
      where = replace_string(where, " and ", ",");
      where = replace_string(where, ", ", ",");
      where = replace_string(where, " ,", ",");
      tryhands = explode(where, ",");
    }
    else {
      what = str;
      tryhands = this_player()->query_wielding_limbs() -
                 this_player()->query_limbs_wielded();
    }
    
    // this should happen here so that weapons on the ground can't
    // somehow give us any of the errors that follow
    if (present(what, this_player()) != this_object()) return 0;
    
    if (!sizeof(tryhands)) {
      message("info", "You dont have any free hands.", this_player());
      return 1;
    }

    foreach (string tryit in tryhands) {
      if (member_array(tryit, this_player()->query_limbs()) == -1) {
        message("info", "You don't have a "+tryit+"!", this_player());
        return 1;
      }
      if (member_array(tryit, this_player()->query_wielding_limbs()) == -1) {
        message("info", "You can't hold a weapon in your "+tryit+".", this_player());
        return 1;
      }
      if (member_array(tryit, this_player()->query_limbs_wielded()) != -1) {
        message("info", "You are already wielding something in your "+tryit+".", this_player());
        return 1;
      }
    }
    
    if (query("skill level") > (int)this_player()->query_skill(query_type()) &&
        !(this_player()->is_monster()))
          return notify_fail("You do not have the talent to use that weapon.\n");

    if (query_wielded()) {
      message("my_action", "You are already wielding that!\n",this_player());
      return 1;
    }

    hands = query_hands();
    if (war == 1 && hands > 1) {
      hands--;
      lower=1;
    }

    if (hands > sizeof(tryhands)) {
      message("info", "You must wield such a weapon with "+
          cardinal(hands)+" hands.\n",
          this_player());
      return 1;
    }

    // if a warrior specifically wields a multi-handed weapon in the
    // original number of required hands, allow it and don't lower the wc
    if (where && lower && sizeof(tryhands) == query_hands()) {
      lower=0;
      hands++;
    }

    if (!hands) hands=1;

    if (functionp(__Weapon["wield"]) && !((*__Weapon["wield"])())) return 1;
    
    ok = (string)this_player()->equip_weapon_to_limb(this_object(), implode(tryhands[0..hands-1],","));

    if(ok) {
        message("my_action", ok, this_player());
        return 1;
    }
    
    if(stringp(__Weapon["wield"]))
      message("my_action", __Weapon["wield"], this_player());
    else
      message("my_action", "You wield "+query_short()+".", this_player());
    
    if (environment(this_player()))
      message("other_action", this_player()->query_cap_name()+" wields "+
        query_short()+".", environment(this_player()), ({ this_player() }));

    __Weapon["wielded"] = this_player();
    __Weapon["limb string"] = " (wielded)";

    if (lower) {
      remove_property("warrior_wield");
      set_property("warrior_wield",1);
      ench=query_property("enchantment");
      remove_property("enchantment");
      set_property("enchantment", -2+ench);
    }

    this_player()->set_disable(1);
    return 1;
}
 
int __Unwield(string str) {
    object ob;
 
    if(!str) return notify_fail("Unwield what?\n");
    if(!id(str)) {
        if(!(ob = parse_objects(this_player(), str)) || (ob != this_object()))
          return notify_fail("You don't have that!\n");
        str = query_name();
    }
    if(!__Weapon["wielded"])
      return notify_fail("You are not wielding that!\n");
    if(functionp(__Weapon["unwield"]) && !((*__Weapon["unwield"])())) return 1;
    __ActuallyUnwield();
    this_player()->set_disable(1);
    return 1;
}
 
void set_ac(int x) { __Weapon["ac"] = x; }

int sharpen(int x) {
   if (__Weapon["wc"] >= orig_wc)
      return 0;
   __Weapon["wc"] += x;
   return 1;
}
 
void set_wc(int x) {
    if(x>20) log_file("illegal", file_name(this_object())+": euid ("+
      geteuid(this_object())+") has a wc of "+x+"\n");
    if(!__Weapon["decay rate"]) __Weapon["decay rate"] = 10000/(x+1);
    __Weapon["wc"] = x;
    if(!__Weapon["original wc"]) __Weapon["original wc"] = x;
   if (!orig_wc)
    orig_wc = x + 1;
   if(x < 5)
     this_object()->set("skill level", x-1);
   else if(x <= 10)
     this_object()->set("skill level", x*8 - 10);
   else
     this_object()->set("skill level", x*15 - 80);
}
 
void set_hit(mixed val) {
    
    __Weapon["hit"] = val; 
}
 
void set_wield(mixed val) {
    
    __Weapon["wield"] = val;
}
 
void set_unwield(mixed val) {
    
    __Weapon["unwield"] = val;
}
 
void set_type(string str) { __Weapon["type"] = str; }
 
void set_hands(int x)
{
 if (x<1 || x > 4) __Weapon["hands"] = 1;
 else __Weapon["hands"] = x;
}

void set_decay_rate(int x) { __Weapon["decay rate"] = x; }
 
void add_poisoning(int x) {
    if(!__Weapon["poison"]) __Weapon["poison"] = x;
    else __Weapon["poison"] += x;
    if(__Weapon["poison"] < 1) map_delete(__Weapon, "poison");
}
 
string query_short() {
    if(!__Weapon["wielded"]) return ::query_short();
    else return ::query_short() + __Weapon["limb string"];
}

string query_long() {
    if(__Weapon["ElemSize"])
        return ::query_long() + "\n%^RESET%^It seems to be imbued with the power of "+__Weapon["Element"]+".";
    return ::query_long();
}
 
int query_ac() { return __Weapon["ac"]; }
 
int query_wc() { return __Weapon["wc"] + query_property("enchantment"); }
int query_original_wc() { return __Weapon["original wc"]; }

 
mixed query_hit() { return __Weapon["hit"]; }
 
mixed query_wield() { return __Weapon["wield"]; }
 
mixed query_unwield() { return __Weapon["unwield"]; }
 
string query_type() { return __Weapon["type"]; }
 
object query_wielded() { return __Weapon["wielded"]; }

int query_decay_rate() { return __Weapon["decay rate"]; }
 
int query_poisoning() { return __Weapon["poison"]; }
 
int is_weapon() { return 1; }
 
void unequip() { if(__Weapon["wielded"]) __ActuallyUnwield(); }
 
void __ActuallyUnwield() {
    int ench;
    __Weapon["wielded"]->remove_weapon_from_limb(this_object());
    if(stringp(__Weapon["unwield"]))
      message("my_action", __Weapon["unwield"], __Weapon["wielded"]);
    else {
      if (!query_theft())
       message("my_action", "You unwield "+query_short()+".",
      __Weapon["wielded"]);
    }
  if (!query_theft() && environment(__Weapon["wielded"]))
    message("other_action", (string)__Weapon["wielded"]->query_cap_name() +
      " unwields "+query_short()+".", environment(__Weapon["wielded"]),
      ({ __Weapon["wielded"] }));
    set_not_equipped();
    if (query_property("warrior_wield")) {
      ench=query_property("enchantment");
      remove_property("enchantment");
      set_property("enchantment", 2+ench);
      remove_property("warrior_wield");
    }
}
 
void set_not_equipped() {
    map_delete(__Weapon, "wielded");
    map_delete(__Weapon, "limb string");
}
 
void decay() {
    if (!query_decay_rate()) return;
    if(!__Weapon["wc"]) return;
    __Weapon["decay status"]++;
    if(__Weapon["decay status"] == __Weapon["decay rate"]) {
        __Weapon["wc"]--;
        set("value", 20+query("value")*__Weapon["wc"]/__Weapon["original wc"]);
        message("environment", "You notice some wear on your "+
          query_short()+".", __Weapon["wielded"]);
        __Weapon["decay status"] = 0;
    }
}

void force_decay()
{
    if(!__Weapon["wc"]) return;
    __Weapon["wc"]--;
    set("value",20+query("value")*__Weapon["wc"]/__Weapon["original wc"]);
    message("environment", "You notice some wear on your "+
      query_short()+".", __Weapon["wielded"]);
    __Weapon["decay_status"] = 0;
}
/*
void set_hit_func(object ob) { set_hit((: ob, "weapon_hit" :)); }

void set_wield_func(object ob) { set_wield((: ob, "extra_wield" :)); }

void set_wield_string(string str) { set_wield(str); }

*/
void set_theft(int x) { theft = x; }

int query_theft() { return theft; }
