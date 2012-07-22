#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 1, "night light" : 0, "indoors" : 1, "no teleport" : 1, "mountain" : 1, "coords" : ({ 137, 15, 0 })]));
  set_short("Dragon Lands North");
  set_long("Inside a dark mountain cave. The tunnel climbs upward to the south where it splits into two separate paths. One path leads south, where it climbs up and through the side of the mountain. The other path leads southeast, where it burrows upward and out of the top of the mountain peak. The only source of light in this cave comes from the two paths to the south, where light collects at the entrance and dully resonates through the cave. The tunnel leads deeper down into the heart of the mountain to the north.");
  set_exits( ([
    "north" : DRAG_ROOMS"dragnorth17.c",
    "south" : DRAG_ROOMS"dragnorth25.c",
    "southeast" : DRAG_ROOMS"dragnorth26.c",
             ]) );
  set_items( ([
             ]) );
}
