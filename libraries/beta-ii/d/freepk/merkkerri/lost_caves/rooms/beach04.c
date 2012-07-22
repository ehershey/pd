#include <std.h>
#include <lost_caves.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("sandy beach");
        set_short("Sandy Beach");
        set_long("To the south is a large cliff, it reaches high into the air. Small amounts of vegetation grows on the face of the cliff. The beach is made up of very white and fine sand, it stretches far off to the east. Waves bring foam to the beach surface, and other various items from the sea. The sea meets the horizon to the north.");  
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
			"northeast"	: ROOMS "beach05.c",
			"west"      : ROOMS "beach03.c",

        ]));
}
