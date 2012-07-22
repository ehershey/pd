
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
     "You can see a ledge here, there may be a way to get up there. The tunnel leads to a plateau part of the cave. "
   );
   set_items( ([
     ({"ledge","plateau"}) : "It's pretty high up.",
     ({"crystals","fragments"}) : "there are none!",
     "stone" : "very smooth well-kept rock.",
   ]) );
   set_exits( ([
     "southeast" : ROOMS"f9",
   ]) );
}

