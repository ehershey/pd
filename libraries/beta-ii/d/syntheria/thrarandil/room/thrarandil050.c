#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("uhreln avenue");
        set_short("Uhreln Avenue");
        set_long("Uhreln Avenue runs from east to west through the center of Thrarandil. More imported goods pass by on Uhreln Avenue than any other street in town. Countless barrels and crates pass by on there way to the other towns of Syntheria. To the south is a small shop, it has a sign hanging from it with the picture of a leaf on it. To the north is a very large building with huge torches sitting on the top of it.");  
        set_properties( ([ 
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
            "torches"  :     "Enourmas torches that pour smoke into the sky.",
        ]));
        set_listen("default", "The sounds of carts going by drowns everything else out.");
        set_smell("default", "The strong smell of sea salt fills the air.");
        set_exits(([
			"east"		: ROOMS "thrarandil049.c",
			"south"     : ROOMS "thrarandilSalve.c",
			"west"      : ROOMS "thrarandil051.c",
        ]));
        
}

