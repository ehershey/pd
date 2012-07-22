#include <std.h>
#include <prudash.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("prudash");
        set_short("Prudash");
        set_long("Small cots line the walls, they look to be made from some old cloth. The floor is lined with furs from the creatures of the forest below. The furs look to be of poor quality, and rather old. The walls have a few small torches fixed to them, they look to be lit quiet often. A small rack sits in the center of the room, it looks to hold weapons, but is currently empty.");  
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
			"southwest" : ROOMS "prudash027.c",
            "north"     : ROOMS "prudash025.c", 
        ]));
}

