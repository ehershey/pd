#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("town",1);
    set_short("Inside the vault");
    set_long(
      "There is nothing inside, it is empty. "
               );
    set_items(([
        "room" : "An empty vault.",
 
    ]));
    set_exits( ([
"out" : TOWN "building",
    ]) );
}
