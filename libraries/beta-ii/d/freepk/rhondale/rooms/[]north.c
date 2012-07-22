#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light" : 2, "night light" : 1, "town" : 1]));
     set_name("Zartha City Market North");
     set_short("Zartha Market North");
     set_day_long("%^BOLD%^BLACK%^Zartha Marketplace%^RESET%^\nThe north side of the marketplace leads into the castle largest castle you have ever seen. The square lies to the south, along with the shops.");
set_night_long("%^BOLD%^BLACK%^Zartha Marketplace%^RESET%^\n%^BOLD%^BLACK%^The night crawls with shadows, everywhere you look you see shapes waiting to lunge at you. The stones underfoot are mouldy and it is hard to keep your footing. The square lies just to the south, and the huge castle looms up to the north.");
     set_items(([

		]));
     set_exits(([
		"north"		: KEEPROOM"castlebridge.c",
		"south"		: KEEPROOM"[].c",
		"east"		: KEEPROOM"[]northeast.c",
		"west"		: KEEPROOM"[]northwest.c"
		]));
}
