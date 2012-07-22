#include <std.h>
#include <wildflower.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("cave",1);
    set_short("A tunnel");
    set_day_long(
      "The tunnel runs east and west.  "

    );

    set_night_long(
      "The tunnel runs east and west."
    );
    set_items(([
        "tunnel" : "A secret tunnel that runs east and west",
        
    ]));
    set_smell("default", "It smells of acid.");
    set_listen("default", "Sounds of a demon screaching");
    set_exits( ([
"west" :  ROOMS "yami1.c",
"east" :  ROOMS "yami4.c",
    ]) );

}
