#include <std.h>
#include <prudash.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("prudash");
        set_short("Prudash");
        set_long("This room seems to be a makeshift barracks, many small cots line the walls. There are several wooden racks used for holding crude weapons. On the north wall there is a small hole, used for archers to shoot out of. The floor is rather bare, only large scratches cover the floor. There are a few small torches fixed to the walls, however it doesn't look like any have been lit for some time.");  
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
			"southeast"	: ROOMS "prudash023.c",
			"northeast" : ROOMS "prudash021.c",
            "west"      : ROOMS "prudash031.c", 
        ]));
}

