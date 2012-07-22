#include <std.h>
#include <guild.h>
#include <ether.h>
inherit ETHERSTD;

void create() {
        ::create();
        set_short("Rhondale Portal");
        set_long(
                "%^BOLD%^%^CYAN%^Ethereal Sub-hall: %^BOLD%^Rhondale%^RESET%^\n"
                "%^RESET%^%^CYAN%^The walls are inlaid with %^BOLD%^sapphires%^RESET%^%^CYAN%^, %^BOLD%^topaz"
                " %^RESET%^%^CYAN%^and %^BOLD%^quartz%^RESET%^%^CYAN%^. The floor is made from a smooth "
                "cold stone, which has swirls of sparkling %^BOLD%^blue%^RESET%^%^CYAN%^ particles in it."
                " A large silver emblem is on the center of the floor, and is surrounded by %^BOLD%^"
                "blue flame%^RESET%^%^CYAN%^.%^RESET%^"
    );
    set_items(([
        "sapphires" : "%^RESET%^%^CYAN%^Precious blue stones that adorn the walls.%^RESET%^",
        "topaz" : "%^RESET%^%^CYAN%^Precious blue stones that adorn the walls.%^RESET%^",
        "quartz" : "%^RESET%^%^CYAN%^Precious blue stones that adorn the walls.%^RESET%^",
        "flame" : "%^BOLD%^%^CYAN%^Blue flame surrounds the silver emblem on the floor.%^RESET%^"
    ]) );
    set_listen("default", "A strange silence fills the room.");
        set_exits( ([
                "hall" : ROOMS "1-4.c",
                "helgrath" : ROOMS "p-helg.c",
                "purgatory" : ROOMS "p-purg.c",
        ]) );        
        set_pre_exit_functions( ({"helgrath"}), ({"lvl_check_helg"}) );
        set_pre_exit_functions( ({"purgatory"}), ({"lvl_check_purg"}) );
        set_pre_exit_functions( ({"hall"}), ({"lvl_check_hall"}) );

}
int lvl_check_helg() {
        if (this_player()->query_level() < 25) {
                write("You are too weak to go to to Helgrath!\n");
                return 0;
        }
	write("%^CYAN%^The flames rise around the emblem and pull back as it opens, to reveal a portal.%^RESET%^\n");
	write("You enter the portal.\n");
        return 1;
}
int lvl_check_purg() {
        if (this_player()->query_level() < 36) {
                write("You are too weak to go to to Purgatory!\n");
                return 0;
        }
	write("%^CYAN%^The flames rise around the emblem and pull back as it opens, to reveal a portal.%^RESET%^\n");
	write("You enter the portal.\n");
        return 1;
}
int lvl_check_hall() {
        if (this_player()->query_guild() != "ethereal") {
                write("You should not be going there!\n");
                return 0;
        }
	write("%^CYAN%^The flames rise around the emblem and pull back as it opens, to reveal a portal.%^RESET%^\n");
	write("You enter the portal.\n");
        return 1;
}
