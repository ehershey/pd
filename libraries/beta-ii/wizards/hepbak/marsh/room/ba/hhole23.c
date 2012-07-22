#include <std.h>
#include <marsh.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("indoors",1);
    set_short("Uwagi's Homes");
    set_long(
      "This is a very strange looking room.  It has ancient artifacts lined up "
       "shelves, which covers all the walls.  The room has an erie glow coming "
       "from a source unknown, but for some reason it also has a calming effect. "

    );
    set_items(([
        "room" : "It's very strange looking.",
        "artifacts" : "You believe some of them have some sort of healing powers.",
        "shelves" : "Other then the artifacts on them, most of the shelves contain herbs.",
        "herbs" : "When mixed together right, it can cure you of anything.",
        "glow" : "It's an erie glow, but has a calming effect about it.",


    ]));
    set_exits( ([
"west" : BA "hhole16",

    ]) );

}
