#include <std.h>
#include <sindarii.h>
inherit ROOM;

object board;

int check_access(object who);

void create() {
  ::create();
  set("short", "Law notice room");
  set("long", "This room is where the board for Law is kept.  There seem "
      "to be so many issues to be constantly dealt with that it "
      "got difficult to keep up with them all.  Thus, this room. "
      "Hopefully this room is restricted to arches only.");
    set_property("light", 2);
    set_exits((["down" : ROOMS "arch",
                "west" : ROOMS "banishboard"]));
    set_property("indoors", 1);
    board = new("std/bboard");
    board->set_name("board");
    board->set_id( ({ "board", "law board" }) );
    board->set_max_posts(3000);
    board->set_location(ROOMS "law");
    board->set("short", "Law board");
    board->set("long", "This board is used to keep track of Law issues.\n");
    board->set_board_id("law");
}

mixed init() {
  ::init();
    if(!archp(this_player()))  {
      write("Access denied.");
      this_player()->move(ROOMS "square.c");
      return 1;
  }
}

int check_access(object who) {
  return ((string)this_player()->query_name() == "inferno" ||
          (string)this_player()->query_name() == "seeker" ||
          (string)this_player()->query_name() == "suluial");
}
