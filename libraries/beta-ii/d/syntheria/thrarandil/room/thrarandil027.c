#include <std.h>
#include <thrarandil.h>
#include <daemons.h>

inherit DOCKS;

void create()
{
    ::create();
        set_name("thrarandil harbor");
        set_short("Thrarandil Harbor");
        set_long("Thrarandil Harbor was built long ago, and is one of the few structures in this city that is repaired regularly. A large pier extends out to the west into the sea. The pier is largely made of wood planks, a few stone pillars are used to support the massive structure. Many large boats can be seen docked, loading and unloading cargo. A small shack sits here near the end of the pier, it looks like it is a small shop.");  
        set_properties( ([ 
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
            "pier"          :   "A large wooden structure made so ships can dock safely.",
            "pillars"       :   "Huge stone pillars that extend down to the sea floor.",
            "ships"         :   "Mostly large transport ships from various regions around the world",
            "shack"         :   "A small shack built into the pier. It looks like it is some type of shop."
        ]));
        set_listen("default", "Many different sounds can be heard from all directions.");
        set_smell("default", "The strong smell of sea salt fills the air.");
        set_exits(([
			"east"		: ROOMS "thrarandil026.c",

        ]));
        set_letter("C");
        
}

