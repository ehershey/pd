#include <std.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("old road");
    set_long(
      "The tree is now blocking your travel to the east.  The town "
      "appears to be vacant, but distant sounds of violence change "
      "your opinion on that matter. "
    );
    set_items(([
        "tree" : "The tree is gigantic and very very old.",
        "town" : "It appears to be a ghost town.",
    ]));
   set_exits( ([ 
        "north" : "/wizards/kabaal/room/myfile/room5.c",
        "southeast" : "/wizards/kabaal/room/myfile/room2.c",
    ]) );
}
