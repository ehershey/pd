#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1, "coords" : ({ 138, 15, 0 })]));
  set_short("Dragon Lands North");
  set_long("The mountain peak levels out and becomes a large plateau. To the west and to the northwest, the plateau rises slightly to become an uneven mountain peak. The path below slides along the plateau and slips over the side of the mountain to the northwest. To the south and southeast, the path widens considerably where it dips slightly and then rises again to connect to a large ridge that runs east and west along the mountan top.");
  set_exits( ([
    "northwest" : DRAG_ROOMS"dragnorth18.c",
    "south" : DRAG_ROOMS"dragnorth27.c",
    "southeast" : DRAG_ROOMS"dragnorth28.c",
             ]) );
  set_items( ([
             ]) );
}
