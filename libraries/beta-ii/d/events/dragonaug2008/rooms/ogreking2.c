#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"instance.c";

void create() {
  ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
  set_short("The thone room of the ogre king");
  set_long("The carpeted aisle way leads south away from the center of the throne room. The aisle reaches a large wall to the north and splits off to the northeast and northwest, around the wall.");
  set_exits( ([
    "south" : DRAG_ROOMS"ogreking1",
    "northwest" : DRAG_ROOMS"ogreking3",
    "northeast" : DRAG_ROOMS"ogreking4",
  ]) );
  set_instance_group_id("Ogre King Throne Instance");
}

void reset() {
  object newGuard;
  ::reset();
  if(!present("guard")) {
    newGuard = new(DRAG_MOBS"ogrekingguard");
    newGuard->move(this_object());
    newGuard->make_permanent();
  }
}
