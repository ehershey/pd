
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
     "The walls here have been smoothed over, this is quite a difference. There is a neatness here that doesnt resemble any normal cave."
   );
   set_items( ([
     "ramp" : "It appears to be a path deeper into the caves.",
     ({"crystals","fragments"}) : "there are none!",
     "stone" : "very smooth well-kept rock.",
   ]) );
   set_exits( ([
     "northeast" : ROOMS"f33",
     "west" : ROOMS"f31",
   ]) );
}

