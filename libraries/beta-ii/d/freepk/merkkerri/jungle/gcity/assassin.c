#include <gcity.h>
#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 object ob;
 ::create();
   set_short("%^YELLOW%^The chamber of assassins%^RESET%^");
   set_long("%^YELLOW%^You have entered the chamber of assassins.  Here you may find sanctuary from the outside world and those who might be seeking revenge for your murderous ways.  Assassins often band together in such places to gain strength in their numbers and to ensure themselves a longer life.%^RESET%^");
   ob = new(BBOARD);
   ob->set_max_posts(100);
   ob->set_board_id("assassin");
   ob->set_location(GCITY "assassin.c");
   ob->set_id(({ "board" }));
   ob->set_short("The assassin's board");
   ob->set_long("Assassins come here to post amongst themselves.");
   ob->set_name("board");
   set_exits(([ "out" : GCITY "gcity26.c" ]));
}
