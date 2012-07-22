#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("gauntlets");
   set_short("raknid gauntlets");
   set_id(({ "raknid guantlets", "guantlets" }));
   set_long("These four thin metal guantlets have only two fingers to "
      "them.");
   set_weight(12);
    set_curr_value("gold", 60);
   set_type("gloves");
   set_limbs(({ "first hand", "second hand", "third hand", "fourth hand" }));
   set_ac(1);
   set_fingers(2);
}

int query_auto_load() {
   if (this_player()->query_race() == "raknid") return 1;
}
