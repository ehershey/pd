#include <dquest.h>
#include <std.h>
inherit ARMOUR;

void init() {
  ::init();
add_action("open_rift", "open");
}

void create() {
    ::create();
set_name("amulet");
set_short("%^RED%^A%^BOLD%^mulet %^RESET%^BOLD%^BLACK%^%^of the %^RESET%^RED%^N%^BOLD%^ether%^RESET%^RED%^ D%^BOLD%^emon%^RESET%^");
set_long("You gaze upon the amulet of the Nether Demon--a symbol worn by demons in reverence of their god.  It appears as an onyx ram's skull with a pentagram etched into the forehead.  The amulet has incredible powers and is a highly sacred artifact.");
set_id(({"holy symbol", "amulet", "amulet of the nether demon", "symbol", "necklace"}));
set_ac(1);
set_weight(2);
set_value(0);
set_type("necklace");
set_limbs(({"torso"}));
set_property("no steal", "you cant!");
}
int open_rift(string what) {
if (what!="rift")return 0;
if (this_player()->query_race()!=("demon"))return 0;
if(environment(this_player())->query_property("no teleport"))
        return notify_fail("You may not teleport here.\n");
write("%^BOLD%^RED%^You open a rift into the underworld.%^RESET%^");
this_player()->move_player(DQUEST "dquest115.c");
return 1;
}


int query_auto_load() {
if (this_player()->query_race()!=("demon")) return 0;
return 1;
}
