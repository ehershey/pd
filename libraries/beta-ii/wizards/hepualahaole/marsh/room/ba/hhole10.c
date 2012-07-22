#include <std.h>
#include <marsh.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("swamp",1);
    set_short("Uwagi's Homes");
    set_long(
      "This hole is not done yet.  The room is very small, and there is an "
      "%^RED%^X%^RESET%^ marked on one of the walls, it must be where a room "
      "will be added on."
          );

    
    set_items(([
        "X" : "Must be where a another room is going.",
        "hole" : "Still being dugged out.",
        "walls" : "If you can call it that, it's not smoothed out yet.",
        "room" : "Very small for now, it is not done yet.",
        "land" : "Steap because of the cliffs.",

    ]));

    set_exits( ([
"out" : BA "ba27",
    ]) );

}
