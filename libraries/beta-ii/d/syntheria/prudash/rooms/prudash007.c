#include <std.h>
#include <prudash.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("prudash");
        set_short("Prudash");
        set_long("The village of Prudash lies high up in the trees of Legodith Forest. Out of the reach of the citizens of Lidelas, who hate the trolls. The village is made up of a few ramshackle buildings made of scrap wood, probably stolen scrap wood. The trees and buildings are connected through a series of bridges, also made of scrap wood. The bridges look like they need constant repair. There are a few torches attached to the buildings for light when it is dark.");  
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
			"east"	    : ROOMS "prudash008.c",
			"west"	    : ROOMS "prudash006.c",
			"southwest"	: ROOMS "prudash005.c",
        ]));
}


