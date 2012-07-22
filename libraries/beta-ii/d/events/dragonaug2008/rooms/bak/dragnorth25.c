#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1, "coords" : ({ 137, 15, 0 })]));
  set_short("The Great Northern Ridge");
  set_long("The Great Northern Ridge\nThis is the furthest east point alonge the great northern ridge. The ridge runs east and west. The ridge physically connects all of the inner high mountain paths to one another, and symbolically connects each of the four dragon races to one another. "
    +"To the south, the ridge drops off into a tremendously deep chasm. There is a very short mountain peak to the north, of which there is a tunnel boring deep into the mountain. To the northwest, the mountain peek drops off into a much shallower crevace than the one to the south.");
  set_exits( ([
    "north" : DRAG_ROOMS"dragnorth21.c",
    "west" : DRAG_ROOMS"dragnorth24.c",
    "east" : DRAG_ROOMS"dragnorth26.c",
             ]) );
  set_items( ([
             ]) );
}
