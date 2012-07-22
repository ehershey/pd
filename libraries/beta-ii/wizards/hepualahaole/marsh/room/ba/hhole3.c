#include <std.h>
#include <marsh.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("swamp",1);
    set_short("Parlor of of home");
    set_long(
      "This hole is a mansion.  It must be owned by the guy that owns the town. "
      "This part of the mansion is called the parlor.  It is very inviting, a chandelier "
      "hangs from the ceiling, a wall to wall carpet, and big oversized chairs lines the room.  "

          );

    
    set_items(([
        "mansion" : "As in a really big home.",
        "hole" : "Must be owned by the guy who owns the town.",
        "parlor" : "It's looks to be a very inviting home.",
        "carpet" : "Very ugly %^GREEN%^carpet%^RESET%^.",
        "chandelier" : "Made with real diamonds and real gold.",

    ]));

    set_exits( ([
"out" : BA "ba8",
"north" : BA "hhole4",
"east" : BA "hhole6",
"west" : BA "hhole5",
"down" : BA "hhole7",
    ]) );

}
