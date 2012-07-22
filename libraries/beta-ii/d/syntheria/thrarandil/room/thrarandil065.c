#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("general store");
        set_short("General Store");
        set_long("The general store of Thrarandil is owned by Orson Urnmori. It sits in a large complex of various shops, making it the central market of the city. The floor is made of fine marble stone, and highly polished. At the back of the shop is a large wooden counter, stained a dark brown. Behind the counter stands Orson, tending to some papers. The walls are covered in large paintings, each one a masterpiece.");  
        set_properties( ([ 
        "no attack"   : 1,
        "no magic"    : 1,
        "indoors"     : 1,
        "no bump"     : 1,
        "light"       : 2,
        "night light" : 2,
        "no steal"    : 1,     
        ]) );
        set_items(([
            "counter"     :   "A large wooden counter, it sits at the back of the room.",
            "paintings"   :   "Masterful works of art, done by some of the greatest masters in history.",
        ]));
        set_listen("default", "The room is very quiet, only the rustling of papers can be heard.");
        set_smell("default", "The air is stale.");
        set_exits(([
			"east"		: ROOMS "thrarandil002.c",
			"north"     : ROOMS "thrarandil066.c",
        ]));
        
}

