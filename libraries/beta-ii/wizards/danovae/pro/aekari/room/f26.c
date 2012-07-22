
#include <std.h>
#include <aekari.h>
inherit ROOM;

void create() {
   ::create();
   set_properties( ([
     "cave" : 1,
     "no castle" : 1,
     "indoors" : 1,
     "light" : 1,
   ]) );
   set_short("Smoothed Cavern");
   set_long(
    "The cave opens up into a cross-section of tunnels here. There is a corridor pretty high up to the northwest. There must be a way to get up there. "
   );
   set_items( ([
     "corridor" : "It's pretty high up. There doesn't appear to be any way up there from here.",
     ({"crystals","fragments"}) : "there are none!",
     "stone" : "very smooth well-kept rock.",
   ]) );
   set_exits( ([
     "east" : ROOMS"f27",
     "southwest" : ROOMS"f35",
   ]) );
}

