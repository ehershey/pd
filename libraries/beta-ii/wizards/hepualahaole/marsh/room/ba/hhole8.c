#include <std.h>
#include <marsh.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("swamp",1);
    set_short("Uwagi's Tool Shack");
    set_long(
      "This is a tool shed. "

          );

   
    set_items(([
        "shed" : "A place to put all the tools for the night",
     
    ]));

    set_exits( ([
"out" : BA "ba18",
    ]) );

}
