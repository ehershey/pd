#include <std.h>
#include <lost_caves.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("sandy beach");
        set_short("Sandy Beach");
        set_long("To the south a large cliff stands, making travel in that direction not possible. Strange large pits have been dug here in the sand, they don't look like they are a natural formation of the beach. The beach is made up of tons of white sand, and stretches far off to the east and west. To the north is the endless sea, it sparkles brilliantly.");  
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
			"southwest"	: ROOMS "beach04.c",
			//"east"      : ROOMS "beach06.c",

        ]));
}

void reset() {
   ::reset();
if (!present("turtle", this_object()))
     new(MOB"sea_turtle.c")->move(this_object());
}
