#include <std.h>
#include <prudash.h>

inherit ROOM;



void create()
{
    ::create();
        set_name("prudash");
        set_short("Prudash");
        set_long("The village of Prudash lies high in the trees, safe from the people of Lidelas. The village is inhabited by descendants of the troll armies from long ago, few free trolls are left. The are many small buildings built into the trees, with long wooden bridges that connect each building. Long vines hang down from each tree, going down to the forest floor. Small torches are fixed to many of the buildings, keeping the area lit no matter what time of day. The wooden bridges sway in the wind, making horrible creaking noises. All of the bridges look rather old, and are in dire need or repair.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,
        "forest"      : 2,
        ]) );
        set_items(([
    	"building"     :   "Small wooden buildings high above the ground.",
    	"torches"      :   "Small torches line the buildings, lighting the village"
        ]));
	    set_listen("default", "The bridges creak with each step.");
	    set_smell("default", "The fresh forest air smells nice.");
	    set_exits(([
			"west"		: ROOMS "prudash001.c",
			"northeast"	: ROOMS "prudash003.c",
        ]));
}


