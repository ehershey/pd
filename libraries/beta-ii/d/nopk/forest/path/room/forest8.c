#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
    set_short("A path in the forest");
    set_long(
      "This path cuts through the forest. The trees grow thick, thier "
      "canopies entertwining blotting out the sky. Small animals play in the "
      "trees. A small cottage lies behind a few trees, almost hidden."
    );
    set_items(([
({"trees", "forest"}) : "Trees of the forest surround the path. "
                    "They are too dense to enter, you'd probably get lost.",
   "path" : "The path was cut through the forest.",
   "bushes" : "A couple small bushes sit along the path.",
    ]));
    set_exits( ([ 

        "south" :  "/d/nopk/forest/path/room/forest7",
        "enter"  : "/d/nopk/forest/path/room/enter1"
    ]) );
}

void reset() {
    if(!present("cottage"))
       new("/d/nopk/forest/path/item/cottage.c")->move(this_object());
    if(!present("squirrel"))
       new("/d/nopk/forest/path/mob/squirrel.c")->move(this_object());
    if(!present("raccoon"))
       new("/d/nopk/forest/path/mob/coon.c")->move(this_object());
}
