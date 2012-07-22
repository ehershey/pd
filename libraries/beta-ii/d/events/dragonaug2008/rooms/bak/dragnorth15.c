#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1, "coords" : ({ 137, 15, 0 })]));
  set_short("Dragon Lands North");
  set_long("The path below seems as if it is joined to the mountain peak to the west of its own accord, rather than being cut from the mountain below. The path is smooth and accommodating, making for easy travel higher up along the mountain top to the southeast. The mountain peak ends to the northwest, allowing the path to spread out before travelling down the mountain to the north. There is a deep crevace to the east, across which can be seen a steep peak with a large hole cut into the side of it.");
  set_exits( ([
    "northwest" : DRAG_ROOMS"dragnorth10.c",
    "southeast" : DRAG_ROOMS"dragnorth20.c",
             ]) );
  set_items( ([
             ]) );
}
