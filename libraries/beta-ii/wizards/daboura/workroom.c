
#include <std.h>
inherit ROOM;
object ob;
void create() {
	::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("Daboura's Workroom");
    set_long(
      "A large room with fine imported carpet. "
      "A larget desk sits in one of the corners of the room. "
      "A large marble fire place is on the far wall."
      " The balance sheet is on the wall."
    );

    set_smell("default", "The air is fresh and sweet/");
    set_listen("default", "The sound of a roaring fire fills the room.");
    set_exits( ([ 
        "square" :  "/d/standard/square",
        "hall"  :  "/d/standard/adv_inner"
    ]) );
    set_items( ([
        "balance" : "Damage Dealing = +1\nDamage Taking = +1\nArea Attack = +1.5\nHealing = +1\nBuffs = +.5\nDebuffs = +.5\nParalyze = +1\nDamage over Time = +.5\nPre-Combat DD = +.5"
      ]) );
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "Dab's idea board" }) );
    ob->set_board_id("dabs board");
    ob->set_max_posts(500);
    ob->set_edit_ok(({ "daboura" }));
    ob->set_location("/wizards/daboura/workroom.c");
    ob->set("short", "Dab's Idea Board");
    ob->set("long", "A large board for dab to post his thoughts on.\n");

}
