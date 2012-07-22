#include <std.h>
#include <simaril.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("syntherian warship");
        set_short("Syntherian Warship");
        set_long("Many small cots line the walls of the inner hull. "
        		 "In the center of the room lie dozens of stacked crates. "
        		 "Several oil lamps are fixed to the walls in random places. "
        		 "This area of the ship seems to be general disarray."
		);  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,
        "town"        : 1,
        "indoors"	  : 1,
        ]) );
        set_items(([
    		"cots"		:	"Many cots that are fixed to the hull.",
    		"cot"		:	"A small cot made of cloth and wood.",
    		"hull"		:	"The inner side of the hull of the ship, it is made of solid wood.",
    		"crates"    :   "Many large wooden boxes that have been stacked rather poorly all across the pier, most of them have strange symbols written on them.",	
	        "crate"     :   "A large wooden box with some straw hanging out of the top of it. it looks like the top is loose and could be opened with a little effort.",
	        ({"symbol", "symbols"})	:	"It looks to be the image of a lamp with some strange glyphs above the lamp.",
			"lamps"		:	"Several small lamps that are fixed to the inner hull, they provide a constant level of light for the room.",
			"lamp"		:	"A lamp made of brass and glass, it burns oil to produce light.",	        
	    ]));
	    set_listen("default", "The room is silent.");
	    set_smell("default", "The smell of burning oil fills the air.");
		set_exits(([
			"south"		: ROOMS"warship04.c",
			"stairs"	: ROOMS"warship02.c",
        ]));
        set_search("crates", "You quickly look over the crates and don't notice anything strange.");
        set_search("crate", "There doesn't seem to be a way into the crate.");
}
 
void reset() {
   ::reset();

}
      


