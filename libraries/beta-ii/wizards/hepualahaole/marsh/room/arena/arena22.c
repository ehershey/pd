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
"north" : ARENA "arena9",
"south" : ARENA "arena10",
"east" : ARENA "arena11",
"west" : ARENA "arean12",
    ])  );
}
