#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("building",1);
    set_short("Inside the grass hut.");
    set_day_long(
      "It's seems to be some kind of portal room."
          );
    set_night_long(
      "It's seems to be some kind of portal room. "
    );
    set_items(([
        "portal" : "Not yet working.  It is still being built",
        "room" : "Looking around, the portal pieces are lying all over the
place.",
    ]));
    set_listen("default", "Humming sounds can be heard");
    set_exits( ([
"out" : TOWN "town",
    ]) );
}
