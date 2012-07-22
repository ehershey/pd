#include <std.h>
#include <wildflower.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("cave",1);
    set_short("Briefing room");
    set_day_long(
      "Briefing room...invitation only.  "

    );

    set_night_long(
      "This room is invitation only...learn how to do it."
    );
    set_items(([
        "room" : "a room.",
    ]));
    set_smell("default", "It smells of acid..");
"north" : ROOMS "wfo.c",
    ]) );

}
