#include <std.h>
#include <cp.h>
inherit ROOM;

object board;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
                "no teleport" : 1, "mountain" : 1]) );
   set_short("Surrounded by mountains");
   set_long(
            "A cleared path within the mountains stretches in each direction "
            "but west. Plant life covers the ground along with some shrubbery."
            " A tall mountain prevents any passage west of here. On the wall of"
            " the mountain travelers throughout the ages have written messages "
            "of their journeys.");
   set_items(([
            "mountain" : "The mountains stretch in all directions. A mountain "
                        "wall prevents access to the west, but contains
messages"
                        " written by travelers of this land.",
            "shrubbery" : "Small shrubs grow at random upon the ground.",
            "plant" : "Plants grow here, scattering the ground."
   ]));
   set_smell("default", "The air is crisp and the air is humid.");
   set_listen("default", "Occassionally a twig can be heard snapping from
afar.");
   set_exits( ([ 
        "north" :  ROOMS "2",
        "east" :  ROOMS "16",
        "south" :  ROOMS "75"]));

          board = new("std/bboard");
          board -> set_name("board");
          board -> set_id(({"board", "face", "wall", "mountain face"}));
          board -> set_max_posts(1000);
          board -> set_edit_ok(({"smoke","smokey", "nulvect"}));
          board -> set_location( ROOMS "1.c");
          board -> set_short("The face of the mountain is covered in writing");
          board -> set_long("The western mountain face is covered in writing.
It seems adventurers, both holy and horrifying, have written down tales of
their own heroics.");
           board->set_board_id("mountain face");
}
