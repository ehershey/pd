#include <petzoo.h>
#include <std.h>
inherit "std/room";

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "The pig pen");
    set("long", "You're in a pig sty.  There are baby piglets running about all over "+
      "the place.  The main path through the zoo is back to the east.");
    set_exits( ([ "west" : ROOMS"pigpen4",
	"east" : ROOMS"zoopath4",
	"south" : ROOMS"pigpen2" ]) );
    set_listen("default", "The sounds of pigs grunting are all around you.");
    set_smell("default", "Smells of pigs and slop fill the air.");
}
void reset() {
    int num_of_mobs = random(MAX_MOB_IN_ZONE)+1;
    int i;
    ::reset();
    if(!present("monster")) {
	for (i=0;i<num_of_mobs;i++){
	    new(MOB"piglet")->move(this_object());
	}
    }
}
