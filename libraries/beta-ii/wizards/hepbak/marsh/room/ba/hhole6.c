#include <std.h>
#include <marsh.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("inside",1);
    set_short("A bedroom");
    set_long(
      "This bedroom looks to be a guest bedroom.  It is very plain "
      "and boring looking."

          );

    
    set_items(([
        "bedroom" : "It's very plain looking.",
     
    ]));

    set_exits( ([
"west" : BA "hhole3",
    ]) );

}
