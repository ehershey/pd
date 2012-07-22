#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("swamp",1);
    set_short("Marsh");
    set_day_long(
      "Walking on a very narrow ledge.  It dosen't feel like a good idea to be
here. "
    );
    set_night_long(
      "Walking on a very narrow ledge.  It dosen't feel like a good idea to be
here. "
    );
    set_items(([
        "ledge" : "Very narrow, and full of squished bones.",
        "bones" : "Something big fell on them.",
       ]));
    set_smell("default", "It smells rotting flesh.");
    set_listen("default", "Sounds of rolling thunder is heared here.");
    set_exits( ([
"up" : ELE "ele7",
"east" : ELE "cliff2",
    ]) );
}
