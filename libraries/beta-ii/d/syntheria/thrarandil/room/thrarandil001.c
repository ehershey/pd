#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("south emmurd street");
        set_short("South Emmurd Street");
        set_long("Emmurd street is mostly travelled by people who are looking to shop, or are on their way home from working at the docks. The south side of the city is where all the residential districts are. The are very few poor people in Thrarandil because of all the work provided by the docks. Large buildings line the streets, each one covered with small sculptures. ");  
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
			"north"		: ROOMS "thrarandil000.c",
			"south"		: ROOMS "thrarandil002.c",
			"west"		: ROOMS "thrarandil066.c",
        ]));
        
}
