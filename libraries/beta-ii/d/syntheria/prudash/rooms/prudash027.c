#include <std.h>
#include <prudash.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("prudash");
        set_short("Prudash");
        set_long("This room is devoid of anything other then a few large stairs. The stairs swing from the northeast up toward the west. The stairs, like the majority of this village, is made of wood. One small torch is fixed to the south wall, it looks like it might be the oldest thing in the village.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,
        "forest"      : 2,
        "indoors"     : 1,
        ]) );
        set_items(([
        "torch"      :   "A small torch fixed to the walls.",
    	
        ]));
	    set_listen("default", "It is rather quiet.");
	    set_smell("default", "The sounds of burning torches echos through the halls.");
	    set_exits(([
			"west"        : ROOMS "prudash028.c",
            "northeast"   : ROOMS "prudash026.c", 
        ]));
}

