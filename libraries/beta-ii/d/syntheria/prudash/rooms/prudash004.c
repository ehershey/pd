#include <std.h>
#include <prudash.h>

inherit ROOM;



void create()
{
    ::create();
        set_name("prudash");
        set_short("Prudash");
        set_long("The village of Prudash lies high up in the trees, safe from the town of Lidelas. The village is mostly just a few ramshackle buildings built into the trees, each one looking to have been built from scrap wood. On each building small torches have been mounted, providing some small amount of light. The buildings are connected by wooden bridges, each one looking more dangerous then the last. The wind howls through the village, masking all other sounds besides the creaking of the bridges impossible to discern.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,
        "forest"      : 2,
        ]) );
        set_items(([
    	"building"     :   "Small wooden buildings high above the ground.",
    	"torches"      :   "Small torches line the buildings, lighting the village"
        ]));
	    set_listen("default", "The bridges creak with each step as the wind howls.");
	    set_smell("default", "The fresh forest air smells nice.");
	    set_exits(([
			"southeast"	: ROOMS "prudash003.c",
			"north"	    : ROOMS "prudash005.c",
        ]));
}

void reset() {
   ::reset();
if (!present("peasant", this_object()))
     new(MOB"troll_peasant.c")->move(this_object());

}
