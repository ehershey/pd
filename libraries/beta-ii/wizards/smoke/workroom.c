#include <std.h>
#include <cp.h>
inherit ROOM;

object board;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
                "no teleport" : 0]) );
   set_long(
            "%^BOLD%^Dragon Lord Smoke calls this old, abandoned "
            "monestary his home. The roof is caved in, stained glass "
            "windows windows are shattered. "
            "What's left of old pews are about "
            "the only thing Smoke keeps around that he keeps out.%^RESET%^");
   set_items(([
            "windows" : "The windows have been shattered... wtf?! ",
            "weed" : "He keeps the weed hidden, dummy!",
            "pews" : "It looks like the old Dragon Smoke tried "
                 "sitting on them."
   ]));
   set_smell("default", "It smells like Cheech and Chong just left.. O.o");
   set_listen("default", "Sublime's Garden Grove rocks out over the magical "
                 "speakers.. ' pickin' up trash on the freeway, feeling "
                 "depressed every day, saying I'm happy when I'm not, "
                 "finding roaches in the pot.. Oooo all these things "
                 "I do... are waiting for you...");
   set_exits( ([ 
        "mountains" :  ROOMS "1",
        "down" : "/d/nopk/standard/adv_inner",
        "ironman" :  "/wizards/ironman/workroom"]));

          board = new("std/bboard");
          board -> set_name("board");
          board -> set_id(({"board", "etcha-sketch"}));
          board -> set_max_posts(1000);
          board -> set_edit_ok(({"smoke","smokey"}));
          board -> set_location( "/wizards/smoke/workroom.c");
          board -> set_short("A giant Etcha-Sketch built into the wall");
          board -> set_long("Man, these things are so cool.. hah! Sketch "
                 "Smoke a message, hint, help, etc.");
           board->set_board_id("etcha-sketch");
}
