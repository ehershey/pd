/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit PIER;

object board;
void create()   {
      ::create();
       set_properties(([
                     "water":1,"light":3,"night light":3,
                      "no bump":1,"no steal":1
                     ]));
       set_listen("default","Pete bellows, 'I will not tolerate combat in my bar! This is your only warning..'");
       set_listen("pete","Pete says, 'I also offer a complete line of special drinks for various people on this reef.  Come back and ask me to mix some for you if ya like.\n\n");

        set_smell("default","The smell of fresh pina coladas fills the air.");
         set_smell("pete","He smells like a strange mixture of wet feathers and coconuts.....");
         set_long("\n  Welcome to Pelican Pete's Pina Colada Perch!!"
                 "\n \n"
                 " A very friendly pelican is sitting on a small boat serving drinks to his customers as they stroll in."
                " A stack of empty glasses are stacked neatly next to Pelican Pete's perch on the bar."
                " There is a menu taped to the side of the boat.");

         set_exits(([
              "east":ROOMS1"room-1e4.c",
              "southeast":ROOMS1"room-1e5.c",
              "south":ROOMS1"room-1d5.c",
              "southwest":ROOMS1"room-1c5.c",
              "west":ROOMS1"room-1c4.c",
              "northwest":ROOMS1"room-1c3.c",
              "northeast":ROOMS1"room-1e3.c",
              "north":ROOMS1"room-1d3.c"
                     ]));
         set_items(([
               "boat":"It's a tiny little craft big enough only to hold Pete's supplies and the pelican himself."
                 ]));
/// board installation               

           board = new("std/bboard");
            board->set_name("board");
           board->set_id(({"board","Pelican Pete's pegboard","pegboard"}));
            board->set_max_posts(100);
           board->set_edit_ok(({"daos","whit","daboura","durst","nesoo","ironman"}));
            board->set_location(ROOMS1+"room-1d4.c");
            board->set_short("Pelican Pete's Pegboard");
            board->set_long("This Pegboard is maintained by Pete and Patty for the free exchange of information between their clients.\n\n");
            board->set_board_id("Pete's Pegboard");
}
// Mob regeneration
void reset() {
         ::reset();
    if(!present("monster"))
    {
MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
            new(MOB1"pelican_patty.c")->move(this_object());
            new(MOB1"pelican_pete.c")->move(this_object());
}
}
