#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("alley way");
        set_short("Alley Way");
        set_long("A thin long alley way, the path is made of old cobble stone. This looks to be where many people dump their trash, there is garbage everywhere. Many tall buildings reach high into the air, blocking out the sky. Water falls from the tops of the buildings down into various puddles on the ground.");  
        set_properties( ([ 
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
            "trash"  :     "Piles of garbage line the alley.",
        ]));
        set_listen("default", "The sounds of dripping water echo throughout the alley.");
        set_smell("default", "The smell of trash permeates everything.");
        set_exits(([
			"south"     : ROOMS "thrarandil056.c",
			"north"     : ROOMS "thrarandil054.c",
        ]));
        
}

