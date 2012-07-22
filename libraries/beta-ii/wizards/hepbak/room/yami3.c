#include <std.h>
#include <wildflower.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("cave",1);
    set_short("Teleport room");
    set_day_long(
      "teleport room.  "

    );

    set_night_long(
      "teleportation room."
    );
    set_items(([
        "room" : "a room.",
    ]));
    set_smell("default", "It smells of acid and smoke..");
    set_listen("default", "Sounds like a vaccum");
    set_exits( ([
"southwest" :  ROOMS "yami4.c",
    ]) );

}
