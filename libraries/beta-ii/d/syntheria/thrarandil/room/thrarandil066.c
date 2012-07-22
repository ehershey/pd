#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("armour store");
        set_short("Armour Store");
        set_long("The armour store of Thrarandil is owned by Delradi Angessy. Hanging on the walls are many different types of armour, from expensive looking cloth to the finest plate mails. In the back of the store is a large counter with a large shield attached to it. The owner of the store stands behind the counter polishing a small circle shield.");  
        set_properties( ([ 
        "no attack"   : 1,
        "no magic"    : 1,
        "indoors"     : 1,
        "no bump"     : 1,
        "light"       : 2,
        "night light" : 2,
        "no steal"    : 1,     
        ]) );
        set_items(([
            "counter"     :   "A large wooden counter, it sits at the back of the room.",
            "armour"      :   "Rare pieces of armour from around the world.",
        ]));
        set_listen("default", "The room is very quiet.");
        set_smell("default", "The air is stale.");
        set_exits(([
			"east"		: ROOMS "thrarandil001.c",
			"north"     : ROOMS "thrarandil033.c",
			"south"     : ROOMS "thrarandil065.c",
			"west"      : ROOMS "thrarandil067.c",
        ]));
        
}

