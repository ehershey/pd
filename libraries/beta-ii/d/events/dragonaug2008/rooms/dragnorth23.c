#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1 ]));
  set_short("The Great Northern Ridge");
  set_long("The Great Northern Ridge\nThis is the furthest east point alonge the great northern ridge. The ridge runs east and west. The ridge physically connects all of the inner high mountain paths to one another, and symbolically connects each of the four dragon races to one another. "
    +"The ridge dips to the south and the southeast into a large plateau. There is a moderately sized mountain peak to the north, of which a small path leads out and around the outer edge. This is the furthest western pont of the great northern ridge, to the west the ridge drops off into obscurity amongst the rest of the mountain features below.");
  set_exits( ([
    "northwest" : DRAG_ROOMS"dragnorth19.c",
    "east" : DRAG_ROOMS"dragnorth24.c",
    "south" : DRAG_ROOMS"dragnorth29.c",
    "southeast" : DRAG_ROOMS"dragnorth30.c",
             ]) );
  set_items( ([
             ]) );
}
