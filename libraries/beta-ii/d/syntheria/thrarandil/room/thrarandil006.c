#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("south emmurd street");
        set_short("South Emmurd Street");
        set_long("The intersection of South Emmurd Street and Irminric Circle Street lies here. South Emmurd Street run through the center of the town north to south, while Irminric Circle Street encircles the southern half of the town. These roads are heavily travelled by people going to and from work. Many large buildings line the street, making it relatively dark. The stones that make up the road are more worn here, it would seem that many large carts come by here often.");  
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
			"north"		: ROOMS "thrarandil005.c",
			"south"		: ROOMS "thrarandil007.c",
			"east"		: ROOMS "thrarandil059.c",
        ]));
        
}
