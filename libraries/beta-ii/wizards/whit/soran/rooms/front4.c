
#include <std.h>
#include <soran.h>
inherit ROOM;

void create() {
     ::create(); 

     set_short("front lawn");
     set_long("The paths continue in intersecting ways.  "
       "The smaller paths lead around the large path, "
       "but end up at the same place.  Green spruce trees "
       "line the side of the path.");
     set_smell( "default","You smell fresh pine here.");
     set_property("indoors",0);
     set_property("light",2);
     set_property("night light",3);
     set_exits(([
     "north": 	ROOMS "front5",
     "west": 	ROOMS "front1",
     ]));
 }

void reset() {
     ::reset();
     if (!present("gardener")) {
         new(MON "gardener.c")->move(this_object());
     }
}

