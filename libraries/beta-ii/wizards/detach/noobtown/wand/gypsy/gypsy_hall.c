#include <std.h>
#include <radyne.h>
inherit HALL;
void create() {
 object ob;
 ::create();
   set_type("wanderer");
   set_short("The Gypsy Hall");
   set_long("Welcome to the Gypsy Hall! The room is "
     "circular and on the walls murals and paintings have been hung. "
     "The murals and paintings are of many different kinds from all over "
     "the realm. The ground is made of wooden planks.");
   ob = new(BBOARD);
   ob->set_max_posts(70);
   ob->set_board_id("gypsy");
  ob->set_location(ROOMS "wand/gypsy/gypsy_hall");
   ob->set_id(({ "board" }));
   ob->set_short("The Gypsy Board of Palm Reading");
   ob->set_long("A large message board has been placed here.\n");
   ob->set_name("subclass");
   set_exits(([ "out" : ROOMS "wand/gypsy/gypsy_join.c" ]));
}
