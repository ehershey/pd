#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"instance.c";

void create() {
  ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
  set_short("The thone room of the ogre king");
  set_long("The easternmost point of the ogre king's throne room. To the northwest, the aisleway leads into the king's audiance chamber. To the southwest, it leads out back into the main aisle.");
  set_exits( ([
    "southwest" : DRAG_ROOMS"ogreking2",
    "northwest" : DRAG_ROOMS"ogreking5",
  ]) );
  set_instance_group_id("Ogre King Throne Instance");
}

void reset() {
  object newGuard;
  ::reset();
  while (!present("guard 2")) {
    newGuard = new(DRAG_MOBS"ogrekingguard");
    newGuard->move(this_object());
    newGuard->make_permanent();
  }
}
