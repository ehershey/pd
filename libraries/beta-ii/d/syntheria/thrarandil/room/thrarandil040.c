#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("dirt path");
        set_short("Dirt Path");
        set_long("This small dirt path goes around the north side of a large wooden shed to the southwest. To the north are grasslands, only small trees break up the horizon. The dirt path has many different types of tracks on it, it looks like many different types of creatures walk this path.");  
        set_properties( ([ 
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
            "shed"          :   "A large wooden shed, it has a small wooden door with a large lock on it.",
        ]));
        set_listen("default", "It is very quiet in this part of town.");
        set_smell("default", "The strong smell of sea salt fills the air.");
        set_exits(([
			"west"      : ROOMS "thrarandil039.c",
			"south"     : ROOMS "thrarandil041.c",
        ]));
        
}

