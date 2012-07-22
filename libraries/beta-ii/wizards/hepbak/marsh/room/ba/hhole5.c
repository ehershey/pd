#include <std.h>
#include <marsh.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("inside",1);
    set_short("A private library");
    set_long(
      "This library is huge!  Floor to ceiling bookshelves, crammed with "
      "books."

          );

    
    set_items(([
        "library" : "Very impressive.  It holds more books then an average library.",
        "books" : "Arranged in accordance of authors.",
        "floor" : "Wall to wall red carpeting.",
        "ceiling" : "It is a mirror, to help reflect light.",
        "bookshelves" : "All but one are as tall as the room.",
        "bookshelf" : "It stands alone in the back of the room.",
 
    ]));

    set_exits( ([
"east" : BA "hhole3",
    ]) );

}
