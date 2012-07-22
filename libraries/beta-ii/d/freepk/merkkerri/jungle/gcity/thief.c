#include <gcity.h>
#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 object ob;
 ::create();
   set_short("%^YELLOW%^The chamber of  thieves%^RESET%^");
set_long("%^YELLOW%^You have entered the chamber of thieves inside the rogue hall.  Thieves may come here and sanctuary from the outside world.  Many shady deals and plots have been born within this chamber.%^RESET%^");
   ob = new(BBOARD);
   ob->set_max_posts(70);
   ob->set_board_id("thief");
   ob->set_location(GCITY "thief.c");
   ob->set_id(({ "board" }));
   ob->set_short("The thieves board");
   ob->set_long("Thieves come here to post amongst themselves.");
   ob->set_name("board");
   set_exits(([ "out" : GCITY "gcity26.c" ]));
}
