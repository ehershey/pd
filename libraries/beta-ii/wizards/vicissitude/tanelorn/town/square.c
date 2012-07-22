
#include <std.h>
inherit ROOM;

void create() {
   ::create();
   set_properties( ([
     "light" : 2,
     "night light" : 2,
     "no attack" : 1,
     "no steal" : 1,
     "no magic" : 1,
     "no bump" : 1,
     "outdoors" : 1
   ]) );
   set_short("Watch Tower Square");
   set_long(
     "Tanelorn Square "
   );
   set_exits( ([
     "north" : "/wizards/vicissitude/tanelorn/town/n1.c",
     "east" : "/wizards/vicissitude/tanelorn/town/e1.c",
     "south" : "/wizards/vicissitude/tanelorn/town/s1.c",
     "west" : "/wizards/vicissitude/tanelorn/town/w1.c"
   ]) );

}



