#include <std.h>
#include <kesis.h>
inherit ROOM;

void create() {
::create();
    set_short("The Outskirts of Kesis");
    set_long("Tall walls block northern and southern view from this point.  The massive gate entrance to "
	"Kesis can be seen to the west, while the current street proceeds to the east.  Large flower boxes "
	"line the walls with many beautiful bouquets.  From the look of the plants, it would appear that "
	"they are well cared for.  The street's massive tiles appear to be freshly polished.");
    
    set_items(([
        "tiles" : "Enormous tiles have been placed here to cover the ground.",
	 ({"flowers", "plants", "bouquets", "basket", "baskets"}) : "Many flower baskets line the street walls "
	            "as a welcome to outsiders as well as a reminder of the state's considerable wealth.",
                                    
	          
    ]));
    set_properties(([
        "light" : 1,
        "night light" : 1,
	"town" : 1,
    ]));
    set_exits(([
        "west" : ROOMS "kesis74.c",
        "east" : ROOMS "kesis76.c",
    ]));
}

