#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
set_property("plain",1);
    set_short("Fenton City Limits");
    set_long(
      "The path here is struck with more pot holes, only a bit smaller "
      "than you ran across earlier.  As you look around you, you see several "
      "run down shacks westward.  The tower is appearing larger and larger"
      "with every footstep you make."
    );
    set_items(([
        "holes" : "They make this an uneasy road to travel.",
        "pot holes" : "They make this an uneasy road to travel.",
        "shacks" : "Very small and rundown.  Quite the eyesore.",
        "tower" : "It is monsterous.  It stands high above the city.",
    ]));
   set_listen("default", "The hustle and bustle of the town surrounds you.");
   set_exits( ([ 
        "east" : ROOMS"room11.c",
        "west" : ROOMS"room13.c",
    ]) );
}
