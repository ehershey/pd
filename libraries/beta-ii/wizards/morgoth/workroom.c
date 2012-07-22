#include <std.h>
inherit ROOM;

void create(){
     object ob;
   ::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
   set_short("Lord Morgoth's Workroom");
   set_long(
     "You Enter The Room And Look Around You. You Get A Strange\n"
     "Feeling In Your Stomach, You Know This Room Is Not Normal.\n"
     "You Now Understand The Evils That Exist In Such A Dark\n"
     "Mind. Morgoth was definitly here.");
   set_smell("default", "An odd smell of burning water is in the air.");
   set_listen("default", "You hear techno music, and lots of typing");
   set_exits( ([
     "square" :  "/d/standard/square",
     "hall" : "/d/standard/adv_inner",
     "dreamland" : "/wizards/morgoth/room/strange1.c"
   ]) );
   ob = new("std/bboard");
   ob->set_name("board");
   ob->set_id( ({ "board", "spell board" }) );
    ob->set_board_id("morgoth");
    ob->set_max_posts(50);
    ob->set_location("/wizards/morgoth/workroom.c");
    ob->set("short", "Morgoth's board");
    ob->set("long", "Morgoth's board in process\n");
   }

void reset(){
   ::reset();
   new("/wizards/morgoth/item/keg.c")->move(this_object());
   new("/wizards/morgoth/mob/shady.c")->move(this_object());
   }
