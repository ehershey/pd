//Gepetto

#include <std.h>

inherit ROOM;
    object board;

void create() {
    ::create();
    set_property("cave",1);
    set_short("deep inside a cave");
set_day_long("%^ORANGE%^%^A large cavern opens ahead. Unusually clean and tidy, it looks as if someone or something lives here. Smaller caves can be seen opening off in several directions. The scorched walls may give an indication to what lives in this place.%^%^RESET%^");
set_night_long("%^RED%^%^A large cavern opens ahead. Unusually clean and tidy, it looks as if someone or something lives here. Smaller caves can be seen opening off in several directions. The scorched walls may give an indication to what lives in this place. Fear would overtake the sensible adventurer at this point.%^%^RESET%^");
    
    set_items(([
             "cavern" : "This cavern is rather large in size and is well kept.
It appears to be someone's home.",
             "walls" : "The walls are scorched and blackened, no doubt caused
by a magical fire of some sort.",
             "caves" : "The caves, like miniature labirynths  lead off in
several directions.",
    ]));

      set_exits(([
                    "square" : "/d/standard/square.c",
                    "hall" : "/d/standard/adv_inner.c",
    ]));

      set_smell("default", "The cavern smells slightly like a hospital.");
      set_listen("default", "Heavy breathing can be heard somewhere in the
distance.");


    board = new("std/bboard");
    board->set_name("board");
    board->set_id( ({ "board", " gepetto's board" }) );
    board->set_max_posts(80);
    board->set_location("wizards/gepetto/workroom.c");
    board->set("short", "Gepetto's board");
board->set("long", "This board is for use by Gepetto and his
friends.");
    board->set_board_id("gepetto");

}
