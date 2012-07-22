#include <std.h>
#include <wildflower.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("forest",1);
    set_short("Outdoor room");
    set_day_long(
      "There are birds chirping in the trees.  "
    );
    set_night_long(
      "Silence fills the night."
    );
    set_items(([
        "room" : "a room.",
    ]));
    set_smell("default", "It smells of outdoors..");
    set_listen("default", "Sounds like a forest");
    set_exits( ([
"up" :   "/wizards/hepualahaole/workroom",
"south" : ROOMS "outdoor3",
    ]) );
}
