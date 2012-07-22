#include <std.h>
#include <kesis.h>
inherit ROOM;

void create() {
::create();
    set_short("The Outskirts of Kesis");
    set_long("Murals on the northern and southern walls proudly depict the founding of this great city.  Massive tiles underfoot are well polished reminders of the enormous wealth in this place.  Stained-glass windows can be seen on the walls above beautiful baskets full of flowers.  Not far to the west, one can clearly see the massive gates leading into the heart of Kesis.");
    
    set_items(([
        "tiles" : "Enormous tiles have been placed here to cover the ground.",
	 ({"flowers", "plants", "bouquet", "basket", "baskets"}) : "Many flower baskets line the street walls as a welcome to outsiders as well as a reminder of the state's considerable wealth.",
                                    
	"windows" : "Battles native to Aciri are depicted in the street windows in beautiful stained-glass.  Many members of Kesis seem to possess this incredible wealth.",
	"murals" : "The murals have been coloured with beautiful, metallic paints.  The northern mural depicts the founding of Kesis by the old god Carnage, while the southern mural depicts the coming together of the city's first governor and his council after the murder of their diety.",         
    ]));
    set_properties(([
        "light" : 1,
        "night light" : 1,
	"town" : 1,
    ]));
    set_exits(([
        "west" : ROOMS "kesis72.c",
        "east" : ROOMS "kesis74.c",
    ]));
}

