#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1, "coords" : ({ 137, 14, 0 })]));
  set_short("Dragon Lands North");
  set_long("The mountain path yawns open and swerves to the southeast, where it is cut in two by a peak which seems to have abruptly risen out of the ground with the intention of impeding passage. The path banks outwards to the east and southeast, leaning slightly out away from the mountain peak and creating a dangerous slope into both mountain crevaces below. To the north the path slopes gently down and out of view. Across the deep crevace to the west can be seen another mountain peak with its own mountain path skirting both sides of it.");
  set_exits( ([
    "north" : DRAG_ROOMS"dragnorth09.c",
    "east" : DRAG_ROOMS"dragnorth12.c",
    "southeast" : DRAG_ROOMS"dragnorth16.c",
             ]) );
  set_items( ([
             ]) );
}
