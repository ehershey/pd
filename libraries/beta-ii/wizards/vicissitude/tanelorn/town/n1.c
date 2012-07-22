
#include <std.h>
inherit ROOM;

void create() {
   ::create();
   set_properties( ([
     "light" : 2,
     "outdoors" : 1
   ]) );
   set_short("Tanelorn");
   set_long(
     "Tanelorn "
   );
   set_exits( ([
     "south" : "/wizards/vicissitude/tanelorn/town/square.c",
     "north" : "/wizards/vicissitude/tanelorn/town/n2.c"
   ]) );

}



