#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("south emmurd street");
        set_short("South Emmurd Street");
        set_long("Emmurd street is mostly travelled by people who are looking to shop, or are on their way home from working at the docks. The south side of the city is where all the residential districts are. Large buildings line the streets, each one covered with small sculptures. Some small crates sit next to one of the buildings, they have some sort of markings on them.");  
        set_properties( ([ 
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
            "buildings"     :   "Large ancient buildings made from a dark stone, each one has dozens of small sculptures.",
            "crates"        :   "Small wooden crates with the symbol of a sea serpant on them.",
        ]));
        set_listen("default", "The sounds of merchants selling wares echoes everywhere.");
        set_smell("default", "The strong smell of sea salt fills the air.");
        set_exits(([
			"north"		: ROOMS "thrarandil003.c",
			"south"		: ROOMS "thrarandil005.c",
        ]));
        
}
