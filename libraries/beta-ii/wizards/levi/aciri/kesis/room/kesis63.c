#include <std.h>
#include <kesis.h>
inherit ROOM;

void create() {
::create();
    set_short("Kesis");
    set_long("The marble-like material utilized in the creation of this city has a rusty orange outer tone to it.  Its edges are gradually tinged green, as if some process of oxidization had altered their appearance.  Beautiful but fragile trees of a fair size line the walls in soil filled gaps which are spaced equidistantly apart.  Each tree sways slightly under the weight of itself, indicating that they are barely structurally sound.  Nevertheless, beautiful flowers bud among their leaves.  The massive tiles of the street appear to have been polished only hours ago.  Wind chimes are suspended from the tops of the walls.");
    
    set_items(([
             ({"material", "stone", "stone material", "marble"}) : "What appears to be marble is orange in colour and fades at its edges into green.",
             "tiles" : "Giant tiles line the street floor.  They have recently been polished.",
             "chimes" : "The musical reputation of Kesis might span the globe if not for Aciri's geographic isolation.",
             "trees" : "They seem quite fragile, with beautiful flowers budding on them.",
    ]));

    set_listen("default", "Your ears are filled with the chimes' tune, but unobtrusively so.");
    set_properties(([
        "light" : 1,
        "night light" : 1,
	"town" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "kesis62.c",
        "south" : ROOMS "kesis64.c",
    ]));
}

