#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
    set_short("A path in the forest");
    set_long(
      "This path cuts through the forest. The trees grow thick, thier "
      "canopies entertwining blotting out the sky. A large rock sits on "
      "the western side of the path. Small animals play in the forest."
    );
    set_items(([
({"trees", "forest"}) : "Trees of the forest surround the path. ",
   "path" : "The path was cut through the forest.",
   "animals" : "A couple small animals play in the trees that surround the path.",
   "rock" : "What could that be doing there?",
    ]));
    set_exits( ([ 
        "south" :  "/d/nopk/forest/path/room/forest3",
        "north"  : "/d/nopk/forest/path/room/forest7"
    ]) );
}
void reset() {
    if(!present("hawk"))
        new("/d/nopk/forest/path/mob/hawk.c")->move(this_object());
    if(!present("raccoon"))
        new("/d/nopk/forest/path/mob/coon.c")->move(this_object());
}
