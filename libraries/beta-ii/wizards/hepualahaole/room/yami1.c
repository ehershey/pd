#include <std.h>
#include <wildflower.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("cave",1);
    set_short("A dark room");
    set_day_long(
      "Dead End.  "

    );

    set_night_long(
      "Evil red eyes glowing in the night."
    );
    set_items(([
        "room" : "A dark cave",
        "eyes" : "Red eyes everywhere glaring at you",
    ]));
    set_smell("default", "It smells like acid.");
    set_exits( ([
"west" :  ROOMS "yami.c",
"tunnel" :  ROOMS "tunnel.c",
    ]) );
    add_invis_exit("tunnel");

}
