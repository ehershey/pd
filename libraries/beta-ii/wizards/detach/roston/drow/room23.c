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
        "attack roston the town to the south. There is members of the "
        "drow army all around, they seem to be haveing fun and getting "
           "drunk.");

set_exits( ([ "east" : "/wizards/detach/roston/drow/room24",
              "west" : "/wizards/detach/roston/drow/room22" ]));
}                                                    
