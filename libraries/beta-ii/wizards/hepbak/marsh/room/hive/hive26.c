#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "The tunnel runs in a diagonal direction.  "
      "A light can be seen in the southern direction. "
     
    );
    set_items(([
        "tunnel" : "It runs in a diagonal direction, and not used recently",
        "light" : "It's off in a distance.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"northeast" : HIVE "hive29",
"southwest" : HIVE "hive21",
    ])  );
}
