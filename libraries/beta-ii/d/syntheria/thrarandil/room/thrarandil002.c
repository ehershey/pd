#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("south emmurd street");
        set_short("South Emmurd Street");
        set_long("Emmurd street is mostly travelled by people who are looking to shop, or are on their way home from working at the docks. Many large buildings line the street, most look to be office buildings for the many different companies that deal with trade. Each building is lined with carvings and sculptures, most look to be of gargoyles.");  
        set_properties( ([ 
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
            "buildings"     :   "Large ancient buildings made from a dark stone, each one has dozens of small sculptures.",
        ]));
        set_listen("default", "The sounds of merchants selling wares echoes everywhere.");
        set_smell("default", "The strong smell of sea salt fills the air.");
        set_exits(([
			"north"		: ROOMS "thrarandil001.c",
			"south"		: ROOMS "thrarandil003.c",
			"west"		: ROOMS "thrarandil065.c",
        ]));
        
}
