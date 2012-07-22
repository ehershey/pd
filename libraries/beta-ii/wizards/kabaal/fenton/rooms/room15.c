#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
set_property("plain",1);
    set_short("inside the city");
    set_long(
      "The dirt road has a turn here.  The mage tower shoots into the sky.  Trees "
      "and bushes make up the side of the road.  You are now nearing the exit of the "
      "town of Fenton and the start of the Forest of Saltor. Shacks are seen to your east. "
      );
    set_items(([
        "road" : "The road is in pretty sad shape.",
        "shacks" : "They rise up from the ground to the east",
        "tower" : "The tower is huge and it appears occupied.",
    ]));
   set_listen("default", "A loud humming emits from the southwest.");
   set_exits( ([ 
        "southwest" : ROOMS"room16.c",
        "east" : ROOMS"room14.c",
    ]) );
}
void reset() {
::reset();
    if(!present("bastard.c"))
      new(MOB"bandit.c")->move(this_object());
      new(MOB"bandit.c")->move(this_object());
}
