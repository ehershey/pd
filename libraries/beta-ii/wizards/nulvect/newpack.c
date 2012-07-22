#include <std.h>

inherit "/wizards/nulvect/std/armour";
inherit BAG;

void init() {
  armour::init();
}

void create() {
    armour::create();
    bag_logic::create();
    set_id( ({"pack", "backpack"}) );
    set_name("backpack");
    set_short("a backpack");
    set_weight(19);
    set_long("A good sized backpack.");
    set_curr_value("gold", 50);
    set_max_internal_encumbrance(800);
    set_possible_to_close(1);
    set_type("backpack");
    set_limbs( ({"torso"}) );
}

string query_long_more() {
  string ret="";
  string *longs = ({
    "query_long_worn",
    "query_long_closed",
    "query_long_contents",
    "query_long_full",
  });
  
  foreach (string func in longs) {
    string tmp;
    tmp = call_other(this_object(), func);
    if (strlen(tmp))
      ret += tmp+"\n";
  }

  return ret;
}

int query_auto_load() {return 1;}

