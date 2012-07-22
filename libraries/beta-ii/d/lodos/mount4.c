#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Traveling on a mountain road");
   set_long("Two walls start to form, then tower above this small "
      "road further ahead. The road is more of a path from here on "
      "to the east. A few dead trees line the pass up ahead.");
set_exits(([ 
                "north" : ROOMS"mount3",
                "up" : "/d/tirunmts/rooms/tirunmts_69.c"]));
   set_properties(([ "light" : 2 ]));
   set_property("mountain",1);
}
