#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
set_property("mountain",1);
    set_short("underground");
    set_long(
      "In this hole, you notice an opening to a cave.  The room is dark and dry. "
      "This was where a witch was sacrificed.  They covered up the hole with a road, "
      "but potholes and some adventurer who can't keep to his own business uncovered "
      "it once again.  There is a cross sticking out of the ground which is where the witch "
      "took her last breath. "
    );
    set_items(([
        "cave" : "You wonder where it could lead.",
        "cross" : "This must be where that nasty banshee was killed when she was alive.",
    ]));
   set_listen("default", "Loud screeches from a banshee pierce your ears.");
   set_exits( ([ 
        "up" : ROOMS"room6.c",
        "cave" : ROOMS"cave1.c",
    ]) );
}
void reset() {
::reset();
    if(!present("banshee.c"))
      new(MOB"banshee.c")->move(this_object());
}
