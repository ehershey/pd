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
"north" : ARENA "arena",
"south" : ARENA "arena3",
"east" : ARENA "arena2",
"west" : ARENA "arean4",
    ])  );
}
