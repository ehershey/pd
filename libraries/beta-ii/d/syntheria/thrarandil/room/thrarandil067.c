#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("armour store");
        set_short("Armour Store");
        set_long("The weapon store of Thrarandil is owned by Dral Worver. Countless weapons line the walls, each one looking more lethal than the last. The floor is made from fine polished marble, it reflects much of the light that strikes it. In the back of the shop is a large desk made of stained wood. Behind the counter is Dral, sharpening a sword while eyeing everyone in the room.");  
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
            "weapons"     :   "Some common and some very strange weapons.",
        ]));
        set_listen("default", "The room is very quiet.");
        set_smell("default", "The air is stale.");
        set_exits(([
			"east"		: ROOMS "thrarandil066.c",
			"north"     : ROOMS "thrarandil032.c",
        ]));
        
}

