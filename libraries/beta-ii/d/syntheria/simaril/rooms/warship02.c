#include <std.h>
#include <simaril.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("syntherian warship");
        set_short("Syntherian Warship");
        set_long("The deck of the ship is full of crates. "
        		 "A large opening in the deck leads down to the lower deck. "
        		 "The bowspirit points to the north. "
        		 "The foremast stands at the center of the deck. "
        		 "Mast shrouds reach up high into the air."
		);  
        set_properties( ([
        "light"       : 2,
        "night light" : 0,
        "town"        : 1,
        ]) );
        set_items(([
    	"deck"     :   "The deck looks old and worn, this ship must not be in service anymore.",
		"bowspirit"	:	"A large wooden pole extending from the front of the ship.", 
		"foremast"	:	"A large wooden mast that has several smaller sails attached to it.",
		"sails"		:	"Sails made from some white material, perhaps a type of cloth.",
		"shrouds"	:	"Thick ropes that are used to support the masts.",
		"opening"	:	"An opening in the deck that leads down to the lower deck.",
		"crates"	:	"A large number of crates, stacked neatly around the ship's deck. Some of the crates have a symbol painted on them.",
		({"symbol", "symbols"})	:	"It looks to be the image of a lamp with some strange glyphs above the lamp.",
		"sea"       :   "The endless sea meets the horizon far to the north, the waves slam into the ship.",
	    ]));
	    set_listen("default", "The crew can be heard moving about the ship doing their duty.");
	    set_smell("default", "Sea salt fills the air, drowning out all other smells.");
		set_exits(([
			"south"		: ROOMS"warship01.c",
			"stairs"	: ROOMS"warship03.c",
        ]));
}
 
void reset() {
   ::reset();

}
      


