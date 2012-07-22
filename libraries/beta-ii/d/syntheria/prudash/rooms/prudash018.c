#include <std.h>
#include <prudash.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("prudash");
        set_short("Prudash");
        set_long("The bridges sway in the wind, letting out loud groans. The bridge circles around a large tree, connecting small shacks built into the tree. Underneath each bridge is a large amount of brush, hiding the bridge from view from underneath. Small torches line the buildings, providing some small amount of light. Far below on the forest floor, objects can be seen moving around. All of the structures in the village seem to have been made from scrap wood, it all looks very unstable.");  
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
			"northeast"	: ROOMS "prudash017.c",
			"west"	    : ROOMS "prudash019.c",
        ]));
}


void reset() {
   ::reset();
if (!present("peasant", this_object()))
     new(MOB"troll_peasant.c")->move(this_object());

}
