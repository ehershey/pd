#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
set_property("plain",1);
    set_short("inside the city");
    set_long(
      "The road turns in many directions here.  Trees loom over head, covering much of the "
      "sky.  The tower stands largely before you.  East you notice a few houses.  To your "
      "north you notice a large amount of trees. "
      );
    set_items(([
        "road" : "The road is in pretty sad shape.",
        "shacks" : "They rise up from the ground to the east",
        "tower" : "The tower is huge and it appears occupied.",
    ]));
   set_listen("default", "A loud humming comes from the tower.");
   set_exits( ([ 
        "northeast" : ROOMS"room15.c",
        "tower" : ROOMS"tower1.c",
        "north" : ROOMS"room17.c",
        "south" : ROOMS"room18.c",
    ]) );
}
void reset() {
::reset();
    if(!present("gargoyle.c"))
      new(MOB"gargoyle.c")->move(this_object());
      new(MOB"gargoyle.c")->move(this_object());
}
