#include <std.h>
#include <simaril.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("syntherian warship");
        set_short("Syntherian Warship");
        set_long("The deck of the ship looks old and worn. "
        		 "Large cannons line each side of the boat. "
        		 "The main mast stands at the center of the deck. "
        		 "Attatched to the mast the main sail is bound tight. "
        		 "Large ropes hang from the masts. "
        		 "To the South is the main cabin, and above that is the bridge. "
        		 "To the North is the ship's bow."
		);  
        set_properties( ([
        "light"       : 2,
        "night light" : 0,
        "town"        : 1,
        ]) );
        set_items(([
    	"deck"     :   "The deck looks old and worn, this ship must not be in service anymore.",
    	({"cannons","cannon"})	:	"Large cannons made from some unknown metal, the cannons lie in a wooden carriage with wheels attached to them.",
		"mast"		:	"A large wooden mast that has several sails attached to it.",
		"sails"		:	"Huge sails made from some white material, perhaps a type of cloth.",
		"ropes"		:	"Thick ropes that are used to support the masts.",
		"cabin"		:	"The cabin where the captain resides.",
		"bridge"	:	"The bridge, at the stern of the ship, is where all of the command decisions are made.",
		"bow"		:	"The front of the ship.", 
		"plank"		:	"A wooden bridge that connects the ship to the pier.",
	    ]));
	    set_listen("default", "The crew can be heard moving about the ship doing their duty.");
	    set_smell("default", "Sea salt fills the air, drowning out all other smells.");
		set_exits(([
			"plank"		: ROOMS"simaril002.c",
			"cabin"		: ROOMS"warshipCabin.c",
			"bridge"	: ROOMS"warshipBridge.c",
			"north"		: ROOMS"warship02.c",
        ]));
}
 
void reset() {
   ::reset();
	if(!present("issul", this_object()))
		new(MOB"issul.c")->move(this_object());

}
      


