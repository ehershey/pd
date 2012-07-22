
#include <std.h>
#include <aekari.h>
inherit ROOM;

void create() {
   ::create();
   set_properties( ([
     "cave" : 1,
     "indoors" : 1,
     "light" : 1,
   ]) );
   set_short("Jagged Cavern");
   set_long(
     "The walls narrow a little in this crude ramp-like area. "
     "It leads deeper into the bowels of this cavern. "
     "The crystal fragments are not scattered here and the stone is "
     "well polished and quite smooth. Clearly this is no ordinary cave."
   );
   set_items( ([
     "ramp" : "It appears to be a path deeper into the caves.",
     ({"crystals","fragments"}) : "there are none!",
     "stone" : "very smooth well-kept rock.",
   ]) );
   set_exits( ([
     "up" : ROOMS"ca60",
     "down" : ROOMS"f1",
   ]) );
}

