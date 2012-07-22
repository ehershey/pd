#include <std.h>
#include <daemons.h>
#include <sindarii.h>
inherit "/std/hall.c";

void create() {
 object board;
 ::create();
   set_properties(([ "light" : 2, "indoors" : 1, "no attack" : 1, "no magic" : 1,
     "no teleport" : 1 ]));
   set_short("The Hall of Monks");
   set_long(
     "Welcome to the Hall of Monks. This hall is for the advancement and general "
     "improvement of each monk. Monks come here that they might train and advance "
     "in their skill away from the other Clergy. %^BOLD%^%^BLUE%^Blue%^RESET%^ "
     "light fills this room. A %^BOLD%^%^BLUE%^magical%^RESET%^ barrier of light "
     "guards the entrance to this hall."
   );
   set_items(([
     "light" : "Mystical%^BOLD%^%^BLUE%^ blue%^RESET%^ light.",
     "barrier" : "The magical barrier protects this hall from intruders.",
     "hall" : "The Monk Subclass Hall."
   ]));
   set_exits(([
	"south" : ROOMS"monk"
   ]));
   this_object()->set_type("clergy", "monk");
    board = new(BBOARD);
    board->set_name("board");
    board->set_id( ({ "board", "monk board" }) );
    board->set_max_posts(80);
    board->set_location(ROOMS"monk_sub");
    board->set("short", "A tack board");  
    board->set("long", "This board is here for monks to post on.\n");
    board->set_board_id("monk_board");
}
