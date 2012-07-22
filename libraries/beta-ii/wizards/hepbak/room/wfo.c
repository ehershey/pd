#include <std.h>
#include <wildflower.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("cave",1);
    set_short("Wildflower's office");
    set_day_long(
      "There is the treasuer chest and desk here.  "

    );

    set_night_long(
      "The guild chest is here and wildflower's desk."
    );
    set_items(([
        "room" : "a room.",
    ]));
    set_smell("default", "It smells of acid..");
    set_listen("default", "Sounds of Wildflower's demons hissing");
    set_exits( ([
"up" :  ROOMS "yami4.c",
"south" : ROOMS "wfo1.c",
    ]) );

}
