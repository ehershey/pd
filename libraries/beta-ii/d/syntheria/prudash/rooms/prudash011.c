#include <std.h>
#include <prudash.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("prudash");
        set_short("Prudash");
        set_long("Many small buildings have been built into the trees here. Each building has small torches built into them, to provide some light at night. Small wooden bridges connect all of the structures in this village. Each bridge, along with all of the buildings, looks to be made from scrap wood. The wood was most likely stolen from the town of Lidelas.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,
        "forest"      : 2,
        ]) );
        set_items(([
    	"building"     :   "Small wooden buildings high above the ground.",
    	"torches"      :   "Small torches line the buildings, lighting the village",
    	"bridge"       :   "Long old bridges made of scrap wood."
        ]));
	    set_listen("default", "The bridges creak with each step as the wind howls.");
	    set_smell("default", "The fresh forest air smells nice.");
	    set_exits(([
			"west"	    : ROOMS "prudash003.c",
			"northeast"	: ROOMS "prudash010.c",
        ]));
}


