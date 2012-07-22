#include <std.h>
#include <prudash.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("prudash");
        set_short("Prudash");
        set_long("Small wooden buildings, made from scrap wood, are built into the trees here. Every building's door is shut, looks like the residents of this village are not very sociable. The buildings are connected by long, thin wooden bridges. The bridges look to be made of the same kind of scrap wood that the buildings are made of. Small torches are attached to each building, giving off small amount of light. A small ladder is here, which leads down to the forest floor.");  
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
			"southeast"	: ROOMS "prudash015.c",
			"west"   	: ROOMS "prudash013.c",
			"down"      : "/d/syntheria/legodith_forest/room/lf011.c",
        ]));
}

void reset() {
   ::reset();
if (!present("guard", this_object()))
     new(MOB"troll_guard.c")->move(this_object());
if (!present("guard 2", this_object()))
     new(MOB"troll_guard.c")->move(this_object());
}
