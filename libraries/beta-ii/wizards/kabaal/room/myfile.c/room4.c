#include <std.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("old road");
    set_long(
      "The tree is now blocking your travel to the west.  The town "
      "is off to the north.  Your path is limited to going north and "
      "southwest. "
    );
    set_items(([
        "tree" : "You are in shock by its size.",
        "town" : "You see a large tower in the distance.",
        "tower" : "After squinting, you notice there's a light on inside.",
    ]));
   set_listen("default", "A loud shiek sends a chill down your spine.");
   set_exits( ([ 
        "north" : "/wizards/kabaal/room/myfile/room8.c",
        "southwest" : "/wizards/kabaal/room/myfile/room2.c",
    ]) );
}
