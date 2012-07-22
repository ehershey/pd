#include <std.h>
#include <lost_caves.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("sandy beach");
        set_short("Sandy Beach");
        set_long("A large cliff stretches up into the sky to the west, it goes straight up, making it impossible to climb. The cliff reaches out into the sea, making any travel to the west impossible. The beach is composed of an almost infinite amount of white sand, it stretches far off to the east. Many small waves slide up onto the beach, deposit foam, and then receding the way they came. The endless sea is to the north, it reaches all the way to the horizon. Small amounts of vegetation grow on the cliff face.");  
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
			"east"	    : ROOMS "beach03.c",
			"south"		: ROOMS "beach01.c",

        ]));
}
