#include <std.h>
#include <sindarii.h>
inherit "/std/hall.c";

void create() {
    object board;
    ::create();
    set_short("The Hall of Knights");
    set_long(
      "Welcome to the hall of the knights! This is a small make shift training "
      "room in a retired knight's home. This place hasn't been really too fixed "
      "up because knights are usually out riding and adventuring. The main room "
      "of the shack is east."
    );
    set_exits(([
	"east" : ROOMS"locked"
      ]));
    this_object()->set_type("fighter", "knight");
    board = new(BBOARD);
    board->set_name("board");
    board->set_id( ({ "board", "knight board" }) );
    board->set_max_posts(80);
    board->set_location(ROOMS"knight_sub");
    board->set("short", "The Knight's Board");
    board->set("long", "This board is here for knights to post on.\n");
    board->set_board_id("knight");
    new(ROOMS"fighter/dummy")->move(this_object());
}
