#include <std.h>
#include <wildflower.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("cave",1);
    set_short("Storage room");
    set_day_long(
      "There is a weapons rack and some lockers.  "

    );

    set_night_long(
      "Lockers and weapons are here."
    );
    set_items(([
        "room" : "a room.",
    ]));
    set_smell("default", "It smells of acid..");
    set_listen("default", "Sounds of demons playing");
    set_exits( ([
"west" :  ROOMS "yami4.c",
    ]) );

}
