#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1, "coords" : ({ 137, 14, 0 })]));
  set_short("Dragon Lands North");
  set_long("The path along the mountain ridge connects with a greater chunk of mountain mass to the southeast, where it prostrates itself before two great rock gateways before sliding into the greater mass of the mountain. The mountain ridge steeply slides into rolling rocks and dirt to the east. The mountain side drops off steeply to the west into the ocean below.");
  set_exits( ([
    "north" : DRAG_ROOMS"dragnorth05.c",
    "southeast" : DRAG_ROOMS"dragnorth10.c",
             ]) );
  set_items( ([
    ({ "gateway", "gateways" }) : "Two large rock structures are on either side of the path. They serve as a symbolic gateway into the dragon lands.",
             ]) );
}
