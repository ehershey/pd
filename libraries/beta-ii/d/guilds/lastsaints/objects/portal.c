#include <std.h>
#include <amun.h>

inherit OBJECT;
void create() {
    ::create();
    set_id(({"portal", "Last Saints Portal"}));
    set_name("Last Saints Portal");
    set_long("%^BOLD%^%^WHITE%^The Last Saints portal links all the halls of the Saints together. You may %^RED%^<enter> %^WHITE%^any of these places:%^RESET%^\n  %^BOLD%^%^YELLOW%^Hall%^RESET%^\n  %^BOLD%^%^YELLOW%^Tirun%^RESET%^\n");
    set_short("%^BOLD%^WHITE%^Last Saints %^YELLOW%^Portal%^RESET%^");
    set_weight(0);
    set_prevent_get("The portal is ethereal and cannot be touched, only passed through.");
}
void init() {
    ::init();
    add_action("travel", "enter");
}
int travel(string str) {
    if (!str || str == "")
	return notify_fail("Where are you going?\n");
/*    if (str == "helgrath") {
	this_player()->move_player(GUILDROOM"helhall.c", "into the portal");
	write("\nStepping through the portal find yourself in Helgrath.\n");
	return 1;
    }
*/
    if (str == "tirun") {
	this_player()->move_player(GUILDROOM"tirunhall.c", "into the portal");
	write("\nStepping through the portal find yourself in Tirun.\n");
	return 1;
    }
    if (str == "hall") {
	this_player()->move_player(GUILDROOM"portal_room.c", "into the portal");
	write("\nStepping through the portal find yourself in the Guild Hall.\n");
	return 1;
    }
/*
    if (str == "lodos") {
	this_player()->move_player(GUILDROOM"lodoshall.c", "into the portal");
	write("\nStepping through the portal find yourself in Lodos.\n");
	return 1;
    }
    if (str == "tenebrae") {
	this_player()->move_player(GUILDROOM"tenehall.c", "into the portal");
	write("\nStepping through the portal find yourself in Tenebrae.\n");
	return 1;
    }
    if (str == "purgatory") {
	this_player()->move_player(GUILDROOM"corinhall.c", "into the portal");
	write("\nStepping through the portal find yourself in Purgatory.\n");
	return 1;
    }
    if (str == "roston") {
	this_player()->move_player(GUILDROOM"rostonhall.c", "into the portal");
	write("\nStepping through the portal find yourself in Roston.\n");
	return 1;
    }
*/
    write("You sure that is a place?");
    return 1;
}
