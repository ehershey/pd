#include <std.h>
#include <lost_caves.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("sandy beach");
        set_short("Sandy Beach");
        set_long("Many small waves slide up onto the beach here, leaving various sea plants behind as the water falls back into the sea. Each plant looks different, there must be a large coral reef to the north. The sands of the beach are made up of a very fine and white sand, it feels very soft to the touch. A large cliff stands to the southeast, it rises high into the air.");  
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
			"east"	    : ROOMS "beach09.c",
			"south"     : ROOMS "beach07.c",

        ]));
}
