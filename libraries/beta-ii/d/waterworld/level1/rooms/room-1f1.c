/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
    ::create();
    set_properties((["water":1,"light":3,"night light":3]));
    set_listen("default","There is a virtual concert of seagulls here.");
    set_long("This area of the beach is completely over-run with seagulls."
      " The seagull nests extend far to the east and right up to the treeline to the north."
              );

    set_exits(([
        "north":"/d/nopk/tirun/beach/5,1,0",
	"east":ROOMS1"room-1g1.c",
	"south":ROOMS1"room-1f2.c",
	"west":ROOMS1"room-1e1.c"
      ]));
    new(PEARLS"black_clam.c")->move(this_object());
}
