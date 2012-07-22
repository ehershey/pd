#include <std.h>
#include <pastarlon.h>
inherit ROOM;
object board;

void create() {
::create();
set_properties( ([ "no attack" : 1, "no magic" : 1, "no bump" : 1, "no steal" : 1, "light" : 2, "town" : 1, "night light" : 2]) );
set_smell("default", "The salty smell of ocean air is mixed with the rusty smell of blood.");
set_listen("default", "The sounds of battle can be heard from all directions.");
set_short("Arlon city square");
set_long("%^BOLD%^%^BLACK%^Dark storm clouds cover the sky.\n%^RESET%^The square of Arlon is situated in the middle of the beach town's Diamond District.  The entire city is in shambles, taken over by the Drow Goddess, Lloth, through her armies.  The one thing in good condition is a statue of the Drow Goddess in the center of the square.  There are large piles of rubbles to the west and east, making exit in those directions impossible.");
set_exits(([ "north" : ROOMS "roads/17.c",
"south" : ROOMS "roads/15.c",]));
set_items(([
({"rubble", "piles of rubble", "pile of rubble", "pile", "piles"}) : "A large pile of rubble blocks the possibility of movement to and from the east and west.",
]));
    board = new("std/bboard");
    board->set_name("pastarlonsquare");
    board->set_id( ({ "board", "past arlon board" }) );
    board->set_max_posts(500);
board->set_edit_ok(({"stormbringer","nulvect","luna","whit","amun","daos","ironman","pyro","randalar","leondal","vian"}));
    board->set_location(ROOMS "square");
    board->set("short", "%^BOLD%^%^BLACK%^a tattered board%^RESET%^");
    board->set("long", "A very well crafted board had been placed here, but has since been tattered and worn.\n");
    board->set_board_id("pastarlonsquare");
}
void reset() {
    ::reset();
        if(!present("statue"))
          new(OBJ "statue")->move(this_object());
}
