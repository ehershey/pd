#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"instance.c";

void create() {
  ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
  set_short("The thone room of the ogre king");
  set_long("The ogre king's audiance chamber. A large open chamber with a few furnishings. There is a podeum to the south, behind it lays the entrance to the king's throne room. To the southeast and the southwest, the aisleway leads back out towards the main entrance.");
  set_exits( ([
    "south" : DRAG_ROOMS"ogreking6",
    "southwest" : DRAG_ROOMS"ogreking3",
    "southeast" : DRAG_ROOMS"ogreking4",
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
