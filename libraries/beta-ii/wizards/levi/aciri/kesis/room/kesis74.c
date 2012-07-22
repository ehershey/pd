#include <std.h>
#include <kesis.h>
inherit ROOM;

void create() {
::create();
    set_short("The Outskirts of Kesis");
    set_long("The walls on either side of this street look rather new and expertly constructed.  Massive tiles on the ground have been recently polished.  It is evident that this city is well cared for and in fact quite wealthy.  Baskets of flowers have been beautifully arranged along the walls.  Large, stained-glass windows can be seen now and then on the street above the baskets, depicting unfamiliar scenes of battle.");
    
    set_items(([
        "tiles" : "Enormous tiles have been placed here to cover the ground.",
	 ({"flowers", "plants", "bouquet", "basket", "baskets"}) : "Many flower baskets line the street walls as a welcome to outsiders as well as a reminder of the state's considerable wealth.",
                                    
	"windows" : "Battles native to Aciri are depicted in the street windows in beautiful stained-glass.  Many members of Kesis seem to possess this incredible wealth.",
	          
    ]));
    set_properties(([
        "light" : 1,
        "night light" : 1,
	"town" : 1,
    ]));
    set_exits(([
        "west" : ROOMS "kesis73.c",
        "east" : ROOMS "kesis75.c",
    ]));
}

