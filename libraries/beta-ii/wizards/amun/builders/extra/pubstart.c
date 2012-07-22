#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
    object board;
    ::create();
    set_properties(([ "light" : 2,  "night light" : 2,  "no steal" : 1,
        "indoors" : 1, "no magic" : 1, "no castle" : 1, "no attack" : 1 ]));
    set_short("Lar's Message Board Room");
    set_long(
      "%^RESET%^%^MAGENTA%^The Drowning Fish Tavern%^RESET%^\n"
      "This is the south end of the bar.  An extremely old message "
      "board hangs from the wall to the south.  The floor, composed "
      "of long pieces of mahogany, has been worn greatly with years "
      "of use.  This is the best place in town to keep up with current "
      "events, as most everyone passing by the bar with any news, will "
      "post it on the message board.  A barkeep tends the bar to the north. ");
    set_items(([
        "bar" : "A large counter that has been polished smooth with years of
use.",
      ]));

    set_exits( ([
        "north" :  ROOMS "pub.c",
      ]) );
    board = new("std/bboard");
    board->set_name("board");
    board->set_id( ({ "board", "tirun board" }) );
    board->set_max_posts(99);
    board->set_edit_ok(({"stormbringer","wraith","nightshade","seeker","detach", "daos", "whit"}));
    board->set_location("d/nopk/tirun/pubstart");
    board->set("short", "Tirun Board");
    board->set("long", "This board is for the newbies.\n");
    board->set_board_id("newbie");
}
