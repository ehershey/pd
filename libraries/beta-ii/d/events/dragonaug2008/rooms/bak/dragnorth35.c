#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1, "coords" : ({ 138, 16, 0 })]));
  set_short("Dragon Lands North");
  set_long("The mountain ridge skirts two deep chasms, one on the east and one on the west, although the one on the east is significantly deeper and wider than that on the west. To the northwest, the mountain ridge connects to a large open space. To the south, the ridge narrows as it blazes a harrowing trail between the eager chasms below.");
  set_exits( ([
    "northwest" : DRAG_ROOMS"dragnorth33.c",
    "south" : DRAG_ROOMS"dragnorth38.c",
             ]) );
  set_items( ([
             ]) );
}
