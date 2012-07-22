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
        "attack roston, the town to the south. There are tents layed out "
       "all around as far as you can see. The drows seem to be very "
        "relaxed and calm. There seems to be a giant gold tent to "
    "the west. all the members of the army seem to be gone.");

set_exits( ([ "west" : "/wizards/detach/roston/drow/room83",
              "east" : "/wizards/detach/roston/drow/room81" ]));
}                                                             
