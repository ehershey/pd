#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1, "coords" : ({ 137, 17, 0 })]));
  set_short("Dragon Lands North");
  set_long("The mountain ridge is thick, wide and sturdy, yet it breeds a sense of fear and unease. The steep drops off the mountain into waiting canyons below on both the east and the west do nothing to ease the dull terror that begins to set in for even the most stalwart of conquerers at such heights. To the southeast, the ridge connects to another plateau which, although large, is smaller than that which lies to the north. This ridge serves merely to connect the two plateaus to each other.");
  set_exits( ([
    "north" : DRAG_ROOMS"dragnorth34.c",
    "southeast" : DRAG_ROOMS"dragnorth40.c",
             ]) );
  set_items( ([
             ]) );
}
