#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("building",1);
    set_short("Inside the hut.");
    set_day_long(
      "There is nothing here."
          );
    set_night_long(
      "There is nothing here. "
    );
    set_items(([
        "grass" : "The grass is not from here.",
        "room" : "There is just the hut, it is empty.",
        "hut" : "It is an empty hut.",
        
    ]));
    set_exits( ([
"out" : TOWN "town3",
    ]) );
}
