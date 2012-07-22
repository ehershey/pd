
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
    "The network of tunnels continues here. There isn't much of consequence here. Only smoothed-over pathways and an ominous purple glow that comes from the north. "
   );
   set_items( ([
     "glow" : "A strange violet light comes from the north. Similar to the torches on the level above. ",
     ({"crystals","fragments"}) : "there are none!",
     "stone" : "very smooth well-kept rock.",
   ]) );
   set_exits( ([
     "north" : ROOMS"f47",
     "east" : ROOMS"f28",
     "west" : ROOMS"f26",
   ]) );
}

