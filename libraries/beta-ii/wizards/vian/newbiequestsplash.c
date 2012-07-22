#include <std.h>
#include <newbiequest.h>
inherit ROOM;
object board;
void create() {
    ::create();
    set_properties( ([ "light" : 3, "night light" : 3]) );
    set_smell("default", "The smell of fresh code resonates in the room...  Newbies must be happy.");
    set_listen("default", "The sound of Daos yelling at random immortals about things they should do to help echoes throughout the room.");
    set_short("The Newbie Quest splash room");
    set_long("A large desk sits in the corner, with a giant chair for Daos to sit at.  There are smaller desks with papers, pencils, and laptops set up for random wizards like Vian to slave over helping him with the newbie quest.");
    set_exits(([        "house" : ROOMS "house.c",
        "vian" : "/wizards/vian/workroom.c"]));
    ;
    set_items(([
      ]));
    board = new("std/bboard");
    board -> set_name("board");
    board -> set_id(({"board","Newbie Quest Codeboard"}));
    board -> set_max_posts(1000);
    board -> set_edit_ok(({"daos", "vian"}));
    board -> set_location("/wizards/vian/newbiequestsplash.c");
    board -> set_short("Newbie Quest's Codeboard");
    board -> set_long("This is the Newbie Quest's workboard, where you may leave any sorts of notes or ideas regarding the newbie quest.");
    board->set_board_id("newbiecodeboard");
}
