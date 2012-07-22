#include <std.h>
#include <sindarii.h>
inherit ROOM;

object board;

void create() {
  ::create();
  set("short", "Banish Board");
  set("long", "This room is where the board for banished IP's is kept. Only post banished IP Addresses.");
    set_property("light", 2);
    set_exits((["east" : ROOMS "law"]));
    set_property("indoors", 1);
    board = new("std/bboard");
    board->set_name("board");
    board->set_id( ({ "board", "banish board" }) );
    board->set_max_posts(9999);
    board->set_location(ROOMS "banishboard");
    board->set("short", "Banish board");
    board->set("long", "This board is used to keep track of banished IP addresses.\n");
    board->set_board_id("banish");
}

mixed init() {
  ::init();
    if(!archp(this_player()))  {
      write("Access denied.");
      this_player()->move(ROOMS "square.c");
      return 1;
  }
}
