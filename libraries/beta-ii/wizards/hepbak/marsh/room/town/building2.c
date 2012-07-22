#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("building",1);
    set_short("Uwagi Town");
    set_long(
      "The building isn't fully finish yet.  There are boards, "
      "hammers, and nails all over the place.  Against one of the makeshift "
      "walls, are empty bookshelves, this is going to be a library."
          );
    set_items(([
        "hammers" : "The are scattered everywhere.",
        "nails" : "They help keep the boards from moving.",
        "bookshelves" : "At least 20 of them are waiting to be put into use.",
        "boards" : "As in lumber.",
        "door" : "The door is as tall as the trees.",
    ]));
    set_exits( ([
"out" : TOWN "town17",
    ]) );
}
