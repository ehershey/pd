#include <std.h>
#include <amun.h>
inherit ARMOUR;
inherit BAG;

void init() {
  armour::init();
}

void create() {
    armour::create();
    bag_logic::create();
    set_id( ({"sack", "leather sack", "leathersack"}) );
    set_name("pack");
    set_short("%^BOLD%^%^BLACK%^A Leather Sack%^RESET%^");
    set_weight(20);
    set_long("%^BOLD%^%^BLACK%^This sack was made to hold all of your little things, whether it be armour, weapons or whatever you wish.%^RESET%^");
    set_curr_value("gold", 100);
    set_max_internal_encumbrance(400);
    set_possible_to_close(1);
    set_type("backpack");
    set_limbs( ({"torso"}) );

}

int query_auto_load() {
    if(this_player()->query_original_guild() == "lastsaints")
	return 1;
}