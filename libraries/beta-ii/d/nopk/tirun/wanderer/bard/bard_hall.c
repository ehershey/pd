#include <std.h>
#include <tirun.h>
inherit HALL;
void create() {
 object ob;
 ::create();
   set_type("wanderer");
   set_short("The Bard Hall");
   set_long("The Bard Hall of song and dance is a place of joy and "
     "fun. Bards love to have fun and sing. Quickly painted on the walls "
     "by someone not all too skilled are pictures of instuments and "
     "bards playing them.");
   set_listen("default", "The sounds of song and dance fill the air.");
  /*
   ob = new(BBOARD);
   ob->set_max_posts(95);
   ob->set_board_id("bard");
    ob->set_location(ROOMS "wand/bard/bard_hall");
   ob->set_id(({ "board" }));
   ob->set_short("The Bard Board of merriment");
   ob->set_long("Bards post songs among other things here.\n");
   ob->set_name("subclass");
  */
   set_exits(([ "north" : ROOMS "wand/bard/bard_join.c" ]));
}
