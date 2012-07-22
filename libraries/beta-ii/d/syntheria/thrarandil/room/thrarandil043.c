#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("north emmurd street");
        set_short("North Emmurd Street");
        set_long("North Emmurd Street passes by the cathedral before it ends, it is a street made of the finest cobble stone. The large cathedral lies to the west, its fine stained glass windows are a marvel to see. To the north lies a large wooden shed, a big contrast to the elegance of the cathedral. Several dirt paths intersect the road here, leading in different directions.");  
        set_properties( ([ 
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
            "shed"          :   "A large wooden shed, it has a small wooden door with a large lock on it.",
            "cathedral"     :   "A large church with many elegant carvings.",
        ]));
        set_listen("default", "It is very quiet in this part of town.");
        set_smell("default", "The strong smell of sea salt fills the air.");
        set_exits(([
			"east"      : ROOMS "thrarandil042.c",
			"northwest" : ROOMS "thrarandil038.c",
			"south"     : ROOMS "thrarandil044.c",
        ]));
        
}

