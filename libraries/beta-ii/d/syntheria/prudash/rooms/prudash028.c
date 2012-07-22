#include <std.h>
#include <prudash.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("prudash");
        set_short("Prudash");
        set_long("There are three staircases that lead in three different directions. Two lead down, while the one to the south leads up. A large fur lines the floor, it comes from a huge beast not native to these lands. Two large torches are fixed on the north wall, each one with an enormous flame burning inside it. Small banners hang from the ceiling, the are tattered and old.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,
        "forest"      : 2,
        "indoors"     : 1,
        ]) );
        set_items(([
        "torch"      :   "A small torch fixed to the walls.",
    	"fur"        :   "A huge fur from some unknown beast.",
    	"banners"    :   "Small banners, blood red in color. They have a picture of an axe sewn into them.",
        ]));
	    set_listen("default", "It is rather quiet.");
	    set_smell("default", "The sounds of burning torches echos through the halls.");
	    set_exits(([
			"west"        : ROOMS "prudash029.c",
            "east"        : ROOMS "prudash027.c", 
            "south"       : ROOMS "prudash032.c",
        ]));
}

