//Aziraphale

#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light" : 2, "night light" : 1, "town" : 1]));
     set_name("Zartha City Market Southeast");
     set_short("Zartha Market Southeast");
     set_day_long("%^BOLD%^BLACK%^Zartha Marketplace%^RESET%^\nIn the southeast of the marketplace the weapon, armour and general goods stores can be found. The stones underfoot are worn smooth from the constant traffic of needy adventurers.");
     set_night_long("%^BOLD%^BLACK%^Zartha Marketplace%^RESET%^\n%^BOLD%^BLACK%^The market is filled with shadows, darkness consumes everything. Buildings to the south and east can barely be made out against the night.");
     set_items(([

		]));
     set_exits(([
		"north"		: KEEPROOM"[]east.c",
		"south"		: KEEPROOM"armourshop.c",
		"east"		: KEEPROOM"weaponshop.c",
		"southeast"	: KEEPROOM"itemshop.c",
		"west"		: KEEPROOM"[]south.c"
		]));
}
