#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("uhreln avenue");
        set_short("Uhreln Avenue");
        set_long("Uhreln Avenue intersects with Irminric Circle Street here. More imported goods pass by on Uhreln Avenue than any other street in town. Countless barrels and crates pass by on there way to the other towns of Syntheria. To the east is a large dirt road which cuts through an endless field. The road heads off into the horizon.");  
        set_properties( ([ 
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
                    "road"         :       "A large dirt road that heads off to the horizon.",
        ]));
        set_listen("default", "The sounds of carts going by drowns everything else out.");
        set_smell("default", "The strong smell of sea salt fills the air.");
        set_exits(([
			"east"		: ROOMS "futurepath",
			"south"     : ROOMS "thrarandil064.c",
			"west"      : ROOMS "thrarandil050.c",
			"north"     : ROOMS "thrarandil048.c",
        ]));
        
}

