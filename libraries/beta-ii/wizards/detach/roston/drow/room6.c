#include <std.h>
inherit ROOM;

void create() {
  ::create();
set_name("Drow Camp");
set_items((["snow"   : "A deep white snow",
            "dirt"  : "A dark brown mixture"]));
set_properties((["light":2, "night light":3]));
set_short("camp");
set_long("This is the drow encampment, where the drows are waiting to "
        "attack roston the town to the south. There are tents layed out "
       "all around as far as you can see. The drows seem to be very "
        "relaxed and clam. there seems to be no troops around here.");

set_exits( ([ "north" : "/wizards/detach/roston/drow/room7",
              "east" : "/wizards/detach/roston/drow/room70",
              "south" : "/wizards/detach/roston/drow/room5" ]));
}                                                             
