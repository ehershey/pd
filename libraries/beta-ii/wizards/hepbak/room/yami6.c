#include <std.h>
#include <wildflower.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("cave",1);
    set_short("Entrance to Arena");
    set_day_long(
      "A arean awaits here.  "

    );

    set_night_long(
      "Need to learn to do mazes and arenas here."
    );
    set_items(([
        "room" : "a room.",
    ]));
    set_smell("default", "It smells blood and sweat..");
    set_listen("default", "Sounds of grunting");
    set_exits( ([
"north" : ROOMS "yami4.c",
    ]) );

}
