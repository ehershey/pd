#include <std.h>
#include <prudash.h>

inherit ROOM;



void create()
{
    ::create();
        set_name("prudash");
        set_short("Prudash");
        set_long("The village of Prudash lies high in the trees, safe from the people of Lidelas. The village is inhabited by descendants of the troll armies from long ago, few free trolls are left. The are many small buildings built into the trees, with long wooden bridges that connect each building. Long vines hang down from each tree, going down to the forest floor. Small torches are fixed to many of the buildings, keeping the area lit no matter what time of day. The trees remain very thick, even at this height off the ground. Down on the ground, many things can be seen moving around. The moving objects looks to be various animals, unaware of the city above.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,
        "forest"      : 2,
        ]) );
        set_items(([
    	"building"     :   "Small wooden buildings high above the ground.",
    	"torches"      :   "Small torches line the buildings, lighting the village"
        ]));
	    set_listen("default", "The wind rustles the leaves.");
	    set_smell("default", "The fresh forest air smells nice.");
	    set_exits(([
			"east"		: ROOMS "prudash002.c",
			"down"		: "/d/syntheria/legodith_forest/room/lf031.c",
        ]));
}

void reset() {
   ::reset();
if (!present("guard", this_object()))
     new(MOB"troll_guard.c")->move(this_object());
if (!present("guard 2", this_object()))
     new(MOB"troll_guard.c")->move(this_object());
}

