#include <std.h>

inherit ROOM;
object board;
void create() {
    ::create();
    set_properties( ([ "light" : 3, "night light" : 3]) );
    set_smell("default", "The smell of the forest is powerful here.");
    set_listen("default", "Animals can be heard.");
    set_short("The splash room of Achronil");
    set_long("%^BOLD%^Achronil can be seen from here.%^RESET%^");
    set_exits(([ "ingame" : "/d/achronil/rooms/.c",
                                "workroom" : "/wizards/vian/workroom"]));
    ;
          board = new("std/bboard");
          board -> set_name("board");
          board -> set_id(({"board","Achronil Codeboard"}));
          board -> set_max_posts(1000);
          board -> set_edit_ok(({"vian"}));
          board -> set_location("/wizards/vian/achronilsplash.c");
          board -> set_short("Achronil's Codeboard");
          board -> set_long("This is Achronil's workboard, where you may leave any sorts of notes or ideas regarding the area Achronil.");
           board->set_board_id("achronil's codeboard");
}


