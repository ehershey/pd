#include <std.h>
#include <guild.h>
#include <ether.h>
inherit ETHERSTD;

void create() {
        ::create();
        set_short("Purgatory Portal");
        set_long(
                "%^BOLD%^%^RED%^Ethereal Sub-hall: %^BOLD%^Purgatory%^RESET%^\n"
                "%^RESET%^%^RED%^The walls are inlaid with %^BOLD%^bloodstones%^RESET%^"
                "%^RED%^, %^BOLD%^rubies %^RESET%^%^RED%^and %^BOLD%^sardonyx%^RESET%^%^RED%^."
                " The floor is made from a smooth cold stone, which has swirls of %^BOLD%^"
                "crimson%^RESET%^%^RED%^ particles in it. A large gold emblem is on the center"
                " of the floor, and is covered in %^BOLD%^blood%^RESET%^%^RED%^.%^RESET%^"
    );
    set_items(([
        "bloodstones" : "%^RESET%^%^RED%^Precious red stones that adorn the walls.%^RESET%^",
        "rubies" : "%^RESET%^%^RED%^Precious red stones that adorn the walls.%^RESET%^",
        "sardonyx" : "%^RESET%^%^RED%^Precious red stones that adorn the walls.%^RESET%^",
        "blood" : "%^BOLD%^%^RED%^A large quantity of blood completely covers a gold emblem.%^RESET%^"
    ]) );
    set_listen("default", "A strange silence fills the room.");
        set_exits( ([
                "hall" : ROOMS "1-4.c",
                "helgrath" : ROOMS "p-helg.c",
                "rhondale" : ROOMS "p-rhon.c",
        ]) );        
        set_pre_exit_functions( ({"helgrath"}), ({"lvl_check_helg"}) );
        set_pre_exit_functions( ({"rhondale"}), ({"lvl_check_rhon"}) );
        set_pre_exit_functions( ({"hall"}), ({"lvl_check_hall"}) );

}
int lvl_check_helg() {
        if (this_player()->query_level() < 25) {
                write("You are too weak to go to to Helgrath!\n");
                return 0;
        }
	write(
		"%^RED%^The blood on the floor begins to boil and rushes away from the gold emblem, "
		"as it rises from the ground. A portal is revealed.%^RESET%^\n"
	);
	write("You enter the portal.\n");
        return 1;
}
int lvl_check_rhon() {
        if (this_player()->query_level() < 36) {
                write("You are too weak to go to to Rhondale!\n");
                return 0;
        }
	write(
		"%^RED%^The blood on the floor begins to boil and rushes away from the gold emblem, "
		"as it rises from the ground. A portal is revealed.%^RESET%^\n"
	);
	write("You enter the portal.\n");
        return 1;
}
int lvl_check_hall() {
        if (this_player()->query_guild() != "ethereal") {
                write("You should not be going there!\n");
                return 0;
        }
	write(
		"%^RED%^The blood on the floor begins to boil and rushes away from the gold emblem, "
		"as it rises from the ground. A portal is revealed.%^RESET%^\n"
	);
	write("You enter the portal.\n");
        return 1;
}
