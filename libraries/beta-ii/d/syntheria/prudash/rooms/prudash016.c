#include <std.h>
#include <prudash.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("prudash");
        set_short("Prudash");
        set_long("Far below on the forest floor, many moving creatures can be seen. Up high in the trees, there are many small wooden buildings. Each building looks to have been made from scrap wood, every piece of wood has a slightly different shade of color to it. Each building is connected by long and narrow bridges, every bridge looks old and dangerous. There are many torches that have been fixed to the buildings, lighting the way at night.");  
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
			"north"	    : ROOMS "prudash015.c",
			"south"   	: ROOMS "prudash017.c",
        ]));
}


void reset() {
   ::reset();
if (!present("peasant", this_object()))
     new(MOB"troll_peasant.c")->move(this_object());

}
