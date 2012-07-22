#include <std.h>
#include <radyne.h>
inherit HALL;
void create() {
 object ob;
 ::create();
   set_type("mage");
   set_short("The Pyromancer Hall");
   set_exits(([ "out" : ROOMS "mage_hall" ]));
   set_long("%^BOLD%^%^WHITE%^Welcome to the Pyromancer Hall!\n%^RESET%^The "
            "air is thick, humid, and increadibly hot. This "
            "room feels like the inside of a furnace, although " 
            "the heat does not seem the hurt. The walls are towering "
            "sheets of flame, except for the steel door leading back "
            "into the mage hall. You may <train [skill] [amount], to "
            "train your skills. You can also <improve [stat]>, to "
            "improve your stats. Lastly, <advance> to request to be "
            "promoted to the next level.");
   ob = new(BBOARD);
   ob->set_max_posts(70);
   ob->set_board_id("pyro");
   ob->set_location(ROOMS "mage/pyromancer/pyromancer_hall.c");
   ob->set_id(({ "board" }));
   ob->set_short("The Pyromancer Board of Flame");
   ob->set_long("A magical board of flames.");
   ob->set_name("board");
}
