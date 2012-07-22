#include <wiz.h>
inherit ROOM;
object board;
void create() {
    ::create();
    set_properties(([ "light" : 2,  "night light" : 2,  "no steal" : 1,
      "no bump" : 1, "no teleport" : 1, "no castle" : 1,
      "no attack": 1, "indoors" : 1 ]));
    set_short("h0h0 hall");
    set_long("woo! you are in wiz's secret h0h0 hall...");
     set_exits(([  "southwest" : WIZHOUSE]));
    board=new("/std/bboard.c");
    board->set_name("board");
    board->set_id(({"board", "wiz board", "leetice board"}));
    board->set_max_posts(77);
    board->set_location(HOUSEROOM"hall.c");
    board->set_short("Wiz's Board");
    board->set_long("This is the leetice board.");
    board->set_board_id("leetice");
}
