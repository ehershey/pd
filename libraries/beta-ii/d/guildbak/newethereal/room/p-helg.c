#include <std.h>
#include <guild.h>
#include "ether.h"
inherit ETHERSTD;

void create() {
        ::create();
        set_short("Helgrath Portal");

        set_long(
                "%^BOLD%^%^GREEN%^Ethereal Sub-hall: %^BOLD%^Helgrath%^RESET%^\n"
                "%^RESET%^%^GREEN%^The walls are inlaid with %^BOLD%^malachite%^RESET%^"
                "%^GREEN%^, %^BOLD%^jade %^RESET%^%^GREEN%^and %^BOLD%^emerald %^RESET%^%^GREEN%^stones."
                " The floor is made from a smooth cold stone, which has swirls of sparkling"
                " %^BOLD%^green%^RESET%^%^GREEN%^ particles in it."
                " A large silver emblem is on the center of the floor, and is surrounded by large"
                " %^BOLD%^vines%^RESET%^%^GREEN%^.%^RESET%^"
        );
        set_items(([
                "malachite" : "%^RESET%^%^GREEN%^Precious green stones that adorn the walls.%^RESET%^",
                "jade" : "%^RESET%^%^GREEN%^Precious green stones that adorn the walls.%^RESET%^",
                "emerald" : "%^RESET%^%^GREEN%^Precious green stones that adorn the walls.%^RESET%^",
                "vines" : "%^BOLD%^%^GREEN%^Large vines which have completely engulfed a silver emblem"
                        " on the floor.%^RESET%^"
    ]) );
        set_listen("default", "A strange silence fills the room.");
        set_exits( ([
                "hall" : ROOMS "1-4.c",
                "purgatory" : ROOMS "p-purg.c",
                "rhondale" : ROOMS "p-rhon.c",
        ]) );        
        set_pre_exit_functions( ({"purgatory"}), ({"lvl_check_purg"}) );
        set_pre_exit_functions( ({"rhondale"}), ({"lvl_check_rhon"}) );
        set_pre_exit_functions( ({"hall"}), ({"lvl_check_hall"}) );

}
int lvl_check_purg() {
        if (this_player()->query_level() < 36) {
                write("You are too weak to go to to Purgatory!\n");
                return 0;
        }	
	write("%^GREEN%^The vines pull back as the silver emblem begins to open. A large portal is revealed.%^RESET%^\n");
	write("You enter the portal.\n");
        return 1;
}
int lvl_check_rhon() {
        if (this_player()->query_level() < 36) {
                write("You are too weak to go to to Rhondale!\n");
                return 0;
        }
	write("%^GREEN%^The vines pull back as the silver emblem begins to open. A large portal is revealed.%^RESET%^\n");
	write("You enter the portal.\n");
        return 1;
}

int lvl_check_hall() {
        if (this_player()->query_guild() != "ethereal") {
                write("You should not be going there!\n");
                return 0;
        }
	write("%^GREEN%^The vines pull back as the silver emblem begins to open. A large portal is revealed.%^RESET%^\n");
	write("You enter the portal.\n");
        return 1;
}
