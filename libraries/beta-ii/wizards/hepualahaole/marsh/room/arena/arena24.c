#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("cave",1);
    set_short("Arena");
    set_long(
      "Inside a mystic fog. "
     
    );
    set_items(([
        "tunnel" : "It is very dark in here.",
  
    ]));
    set_exits( ([
"north" : ARENA "arena5",
"south" : ARENA "arena6",
"east" : ARENA "arena7",
"west" : ARENA "arean8",
    ])  );
}
