#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("dirt road");
        set_short("Dirt Road");
        set_long("A thin dirt road that runs off of the main road. This road looks like it is very old, there is no grass anywhere on it, and the ground is packed down hard. Some old crates sit neatly stacked next to one of the houses. The buildings on this street look to be old and decrepit, this is where most of the dock hands live.");  
        set_properties( ([ 
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
            "buildings"     :   "Small homes for all the workers. Each home has little window that looks out onto the steet.",
            "crates"        :   "Several large crates stacked up against a house, it almost looks like they are hiding something.",
        ]));
        set_listen("default", "It is rather quiet in this part of town.");
        set_smell("default", "The strong smell of sea salt fills the air.");
        set_exits(([
                        "northwest"     : ROOMS "thrarandil015.c",
                        "south"         : ROOMS "thrarandil013.c",
        ]));
        
}

