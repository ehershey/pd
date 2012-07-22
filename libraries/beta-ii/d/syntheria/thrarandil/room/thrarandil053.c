#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("draelm's magic shop");
        set_short("Draelm's Magic Shop");
        set_long("Draelm's Magic Shop is a world famous importer of rare and powerful magical items. The shop has a large counter near the back of the room, it looks to be made of marble. On the east wall is a large fireplace with a large fire roaring in it.  A giant chandelier hangs from the ceiling, made completely of crystal. Draelm stands behind the counter ready to help any customers.");  
        set_properties( ([ 
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
            "fireplace"  :     "A large stone fireplace with a roaring fire.",
            "fire"       :     "The fire comes up from nothing, it must be magical in origin.",
            "counter"    :     "A huge marble counter, it reflects the dancing light of the fire.",
            "chandelier" :     "An expensive looking light fixture made of pure crystal.",
        ]));
        set_listen("default", "The crackling of the fire echoes around the room.");
        set_smell("default", "The air is stale.");
        set_exits(([
			"north"		: ROOMS "thrarandil052.c",
        ]));
        
}

