#include <std.h>
#include <prudash.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("prudash");
        set_short("Prudash");
        set_long("This appears to be a barracks of some sort, small cots line the walls. A small empty rack stands in the center of the room, presumably it is for storing weapons. Some small furs line the floor, they all look to be from animals of the forest below. Small torches line the walls, each one looks like it is lit very often.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,
        "forest"      : 2,
        "indoors"     : 1,
        ]) );
        set_items(([
        "torches"      :   "Small torches fixed to the walls.",
    	"hole"         :   "A small hole angled towards the ground, it can be used by archers to shoot through.",
    	"fur"          :   "The fur of a large bear like creature, it must have been a mighty beast.",
        ]));
	    set_listen("default", "It is rather quiet.");
	    set_smell("default", "The sounds of burning torches echos through the halls.");
	    set_exits(([
			"south"  	: ROOMS "prudash026.c",
            "west"      : ROOMS "prudash024.c", 
        ]));
}

