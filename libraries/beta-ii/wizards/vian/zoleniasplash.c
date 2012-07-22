#include <std.h>
#include <zolenia.h>

inherit ROOM;
object board;
void create() {
    ::create();
    set_properties( ([ "light" : 3, "night light" : 3]) );
    set_smell("default", "The overwhelming mixed scents of dirt, sweat, blood,
sweat, and rotting flesh fill the air.");
    set_listen("default", "The weak, crying roars of dragons can be heard
throughout Zolenia, loud enough to pierce the deepest, darkest corners..");
    set_short("The splash room of Zolenia");
    set_long("%^BOLD%^%^BLACK%^The small, dirty cell in the prisons of Tenebrae has no prisoners.  It is rumored to be a magical cell, where the prisoners have escaped for years.  The guards are perplexed, however, as there are no holes in the walls, just dirt...%^RESET%^");
    set_exits(([        "dig" : ROOMS "1.c",
"ingame" : "/d/zolenia/rooms/43.c",
                                "workroom" : "/wizards/vian/workroom"]));
    ;
   set_items(([
         "dirt" : "The dirt seems really lose, as if you could dig through it
with just your hands.",
    ]));
          board = new("std/bboard");
          board -> set_name("board");
          board -> set_id(({"board","Zolenia Codeboard"}));
          board -> set_max_posts(1000);
          board -> set_edit_ok(({"vian"}));
          board -> set_location("/wizards/vian/zoleniasplash.c");
          board -> set_short("Zolenia's Codeboard");
          board -> set_long("This is Zolenia's workboard, where you may leave
any sorts of notes or ideas regarding the area Zolenia.");
           board->set_board_id("zolenia's codeboard");
}

