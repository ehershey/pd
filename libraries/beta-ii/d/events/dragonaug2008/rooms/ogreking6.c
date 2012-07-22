#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"instance.c";

void create() {
  ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
  set_short("The thone room of the ogre king");
  set_long("The ogre king's throne room. There is a large chair on top of a raised wooden platform in the middle of the room, facing towards the north. Shoddy carpeting extends from the chair, down the platform, and out the northern exit.");
  set_exits( ([
    "north" : DRAG_ROOMS"ogreking5",
  ]) );
  set_instance_group_id("Ogre King Throne Instance");
}

void reset() {
  object newGuard;
  ::reset();
  while (!present("guard 3")) {
    newGuard = new(DRAG_MOBS"ogrekingguard");
    newGuard->move(this_object());
    newGuard->make_permanent();
  }
  if(DRAG_D->query_data("canKillOgreKing")) {
    if(!present("ogre king"))
      new(DRAG_MOBS"ogreking")->move(this_object());
  }
}

int make_king_killable() {
  object king = present("ogre king", this_object());
  if(!king) return 0;
  return king->make_attackable();
}

void make_king_unkillable() {
  object king = present("ogre king", this_object());
  if(!king) return;
  king->make_unattackable();
}
