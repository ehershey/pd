#include <std.h>
#include <kesis.h>
inherit ROOM;

void create() {
::create();
    set_short("Kesis");
    set_long("The overwhelming beauty of this city street defies monotony in spite of its uniformity.  With the greenish tinged marble, potted flowers and stained-glass windows repeating themselves on and on, there is still an inexplicable sense of interest generated by any different vantage point.  Perhaps a kind of magic has been synthesized with the archicture and design of this place.  Elaborate chimes are suspended from wooden supports at the wall tops, spaced twenty or so feet apart.");
    
    set_items(([
             "gate" : "The massive gate is intricately composed of three dimensional, puzzle-like parts, with massive green doors that together look like a tortoise shell.",
             ({"flowers", "pots", "flora"}) : "The tiny but beautiful flowers are potted in hand-made, ceramic pots.  Great care has been put into their making.",
             ({"material", "stone", "stone material", "marble"}) : "The white marble is artifically tinged green.  The rock takes on an unique look.",
             "tiles" : "Giant tiles line the street floor.  They have recently been polished.",
             "chimes" : "The musical reputation of Kesis might span the globe if not for Aciri's geographic isolation.",    
    ]));

    set_listen("default", "The gentle sound of chimes can be heard on the wind.");
    set_properties(([
        "light" : 1,
        "night light" : 1,
	"town" : 1,
    ]));
    set_exits(([
        "west" : ROOMS "kesis68.c",
        "east" : ROOMS "kesis71.c",
    ]));
}

