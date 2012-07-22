#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    object board;
    ::create();
    set_properties( ([ "light" : 2]) );
    set_short("Lars' message board room.");
    set_day_long(
      "This part of the tavern holds the Tirun Board. "
      "Locals come here to hang out, visit, and keep up "
      "with events happening around the city. The bar is "
      "to the north."
    );

    set_items(([
        "bar" : "A large counter that has been polished smooth with years of use.",
    ]));
    set_exits( ([
        "north" :  ROOMS "pub.c",
    ]) );

    board = new("std/bboard");
    board->set_name("board");
    board->set_id( ({ "board", "tirun board" }) );
    board->set_max_posts(80);
    board->set_location("d/standard/pub2");
    board->set("short", "Tirun Board");
    board->set("long", "This board is for the newbies.\n");
    board->set_board_id("newbie");
}

