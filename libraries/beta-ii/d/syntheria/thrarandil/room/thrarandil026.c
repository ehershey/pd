#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("thrarandil harbor");
        set_short("Thrarandil Harbor");
        set_long("Thrarandil Harbor was built long ago, and is one of the few structures in this city that is repaired regularly. A large pier extends out to the west into the sea. The pier is largely made of wood planks, a few stone pillars are used to support the massive structure. Many large boats can be seen docked, loading and unloading cargo.");  
        set_properties( ([ 
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
            "pier"          :   "A large wooden structure made so ships can dock safely.",
            "pillars"       :   "Huge stone pillars that extend down to the sea floor.",
            "ships"         :   "Mostly large transport ships from various regions around the world",
        ]));
        set_listen("default", "Many different sounds can be heard from all directions.");
        set_smell("default", "The strong smell of sea salt fills the air.");
        set_exits(([
			"east"		: ROOMS "thrarandil025.c",
			"north"     : ROOMS "thrarandilWhall.c",
			"west"      : ROOMS "thrarandil027.c",
        ]));
        
}

