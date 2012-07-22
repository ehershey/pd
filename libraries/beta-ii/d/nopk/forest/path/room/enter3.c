#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("A small cottage");
    set_long(
      "This is the basement of the small cottage. It's more of a hole dug into the ground "
      "than anything else, but looks as though it's a storage room. There is a bunch of "
      "old and useless crap down here. Hanging up on a coat hanger is an old beat up coat "
      "that seems to cry out for attention."
    );
    set_items(([
   "crap" : "Just a bunch of worthless crap....",
   "hanger" : "Just a coat hanger, nothing great.",
    ]));
    set_exits( ([ 
        "up" :  "/d/nopk/forest/path/room/enter1"
    ]) );
}
void reset() {
    if(!present("coat"))
        new("/d/nopk/forest/path/item/coat.c")->move(this_object());
}

