#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("uhreln avenue");
        set_short("Uhreln Avenue");
        set_long("Uhreln Avenue runs from east to west through the center of Thrarandil. More imported goods pass by on Uhreln Avenue than any other street in town. Countless barrels and crates pass by on there way to the other towns of Syntheria. A large cathedral stands to the north, it is made from some sort of dark green stone. To the south is a large building with a sign hanging off of it, on the sign is a picture of a shield.");  
        set_properties( ([ 
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
            "cathedral"     :   "A large church with many elegant carvings.",
        ]));
        set_listen("default", "The sounds of carts going by drowns everything else out.");
        set_smell("default", "The strong smell of sea salt fills the air.");
        set_exits(([
			"east"		: ROOMS "thrarandil000.c",
			"west"      : ROOMS "thrarandil032.c",
			"south"     : ROOMS "thrarandil066.c",
        ]));
        
}

