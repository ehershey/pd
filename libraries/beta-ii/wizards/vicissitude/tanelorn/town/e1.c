
#include <std.h>
inherit ROOM;

void create() {
   ::create();
   set_properties( ([
     "light" : 2,
     "outdoors" : 1
   ]) );
   set_short("Watch Tower Square");
   set_long(
     "Tanelorn Square "
   );
   set_exits( ([
     "west" : "/wizards/vicissitude/tanelorn/town/square.c",
     "east" : "/wizards/vicissitude/tanelorn/town/e2.c"
   ]) );

}



