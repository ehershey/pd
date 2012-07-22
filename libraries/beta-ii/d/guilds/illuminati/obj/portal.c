#include <std.h>
#include <illuminati.h>

inherit OBJECT;

void create() {
    ::create();
    set_id(({"portal", "arch", "golden arch", "archway", "golden archway", "ilarchgate"}));
    set_name("Illuminati archway");
    set_long("%^ORANGE%^The Illuminati archway. It links all the halls of the Illuminati together.\n\nYou may %^BOLD%^WHITE%^<enter>%^RESET%^ORANGE%^ any of these places:\n  %^BOLD%^WHITE%^Hall\n  %^BOLD%^WHITE%^Tirun\n");
    set_short("%^YELLOW%^Golden %^WHITE%^archway%^RESET%^");
    set_weight(0);
    set_prevent_get("The arch is ethereal and cannot be touched, only passed through.");
}

void init() {
    ::init();
    add_action("travel", "enter");
}

int travel(string str) {
    if (!str || str == "")
	return notify_fail("Where are you going?\n");
    if( str != "hall" && str != "tirun" ) {
	write("You walk through the arch, but nothing happens.");
	return 1;
    }
    if (str == "tirun") {
	this_player()->move_player(ILROOM"tirunhall.c", "into the arch");
	write("\n%^BOLD%^WHITE%^Stepping through the arch find yourself in Tirun.%^RESET%^\n");
	return 1;
    }
    if (str == "hall") {
	this_player()->move_player(ILROOM"mainportal.c", "into the arch");
	write("\n%^BOLD%^WHITE%^Stepping through the arch find yourself in the Tower of Light.%^RESET%^\n");
	return 1;
    }



    write("%^BOLD%^BLACK%^You step through the arch but nothing happens.%^RESET%^");
    return 1;
}
