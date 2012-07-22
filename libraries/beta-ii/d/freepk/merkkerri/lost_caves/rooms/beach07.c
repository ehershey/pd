#include <std.h>
#include <lost_caves.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("sandy beach");
        set_short("Sandy Beach");
        set_long("To the very north the beach extends out into the sea a little further, then snakes around the cliff to the east. The cliff rises sharply into the air, it would be impossible to scale. The sand of the beach are a bright white in color, and reflect all the light beamed to them. To the far north lies the endless sea, which stretches to the horizon.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,]) );
        set_items(([
    	"beach"    :  "The beach is composed of an endless amount of white sand.",
    	"sea"    :  "The endless sea sparkles.",
    	"cliff"    : "A very tall sheer cliff, it looks like it is impossible to scale.",
	    ]));
	    set_listen("default", "The sounds of waves fill the air.");
	    set_smell("default", "The smell of sea salt is everywhere.");
	    set_exits(([
			"west"	    : ROOMS "beach06.c",
			"north"     : ROOMS "beach08.c",
			"northeast" : ROOMS "beach09.c",

        ]));
}
