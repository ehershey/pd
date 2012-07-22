#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"instance.c";

void create() {
  ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
  set_short("The thone room of the ogre king");
  set_long("A large entrance hall, this is the entrance to the ogre king's throne room. Two large doors to the south lead out into the cave outside. To the north, the carpeted aisleway leads deeper into the throne room.");
  set_exits( ([
    "north" : DRAG_ROOMS"ogreking2",
    "out" : DRAG_ROOMS"ogrekingentrance",
  ]) );
  add_post_exit_function("out", "do_give_up");
  set_instance_group_id("Ogre King Throne Instance");
  set_instance_dump_area("Ogre King Throne Instance", DRAG_ROOMS"ogrekingentrance");
}

void do_give_up() {
  DRAG_D->ogre_king_giveup(this_player()->query_name());
  write("As you flee for safety, the ogre king's guards regroup behind you.");
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
