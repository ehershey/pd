#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1, "coords" : ({ 138, 15, 0 })]));
  set_short("The Great Northern Ridge");
  set_long("The Great Northern Ridge\nThis is the furthest east point alonge the great northern ridge. The ridge runs east and west. The ridge physically connects all of the inner high mountain paths to one another, and symbolically connects each of the four dragon races to one another. "
    +"The mountain top to the south rises up out of the ground and obstructs any view in that direction. The ridge ends to the east, where it leads down a mountain path to the southeast before dropping off the side of the mountain.");
  set_exits( ([
    "northwest" : DRAG_ROOMS"dragnorth22.c",
    "west" : DRAG_ROOMS"dragnorth27.c",
    "southeast" : DRAG_ROOMS"whitecaveoutside",
    //"south" : (not an actual exit), a mesa covered with trees
             ]) );
  set_items( ([
             ]) );
}
