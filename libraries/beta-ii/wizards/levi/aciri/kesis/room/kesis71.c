#include <std.h>
#include <kesis.h>
inherit ROOM;

void create() {
::create();
    set_short("Kesis");
    set_long("The massive gate entrance to Kesis lies to the east.  The massive walls continue here and reassure the residents of this district that they are safe from invasive attack.  Instead of large flower baskets here, there are smaller pots that contain even more beautiful and exotic flora.  The pots are ceramic and hand made.  There are several small, triangular, stained-glass windows along the walls.  Massive tiles line the ground level of the street.  All of the stone materials here are made of some white marble that has been subtly tinged green by some master-process.");
    
    set_items(([
             "gate" : "The massive gate is intricately composed of three dimensional, puzzle-like parts, with massive green doors that together look like a tortoise shell.",
             ({"flowers", "pots", "flora"}) : "The tiny but beautiful flowers are potted in hand-made, ceramic pots.  Great care has been put into their making.",
             ({"material", "stone", "stone material", "marble"}) : "The white marble is artifically tinged green.  The rock takes on an unique look.",
             "tiles" : "Giant tiles line the street floor.  They have recently been polished.",
    ]));
    set_properties(([
        "light" : 1,
        "night light" : 1,
	"town" : 1,
    ]));
    set_exits(([
        "west" : ROOMS "kesis70.c",
        "east" : ROOMS "kesis72.c",
    ]));
}

