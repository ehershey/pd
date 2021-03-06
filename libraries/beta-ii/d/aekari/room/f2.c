
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
     "southeast" : ROOMS"f3",
     "north" : ROOMS"f1",
   ]) );
}
void reset() {
   ::reset();
   if(!present("yellow guard"))
   new(NPC"ae_magi2.c")->move(this_object());
   if(!present("guard 2"))
   new(NPC"ae_guard.c")->move(this_object());
}


