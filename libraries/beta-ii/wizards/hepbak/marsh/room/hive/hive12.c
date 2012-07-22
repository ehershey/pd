#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "The tunnel here runs in a diagonal direction.  It doesn't "
      "appear to be used much. "
    );
    set_items(([
        "tunnel" : "It runs in a diagonal direction, and not used recently",
 
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"northeast" : HIVE "hive21",
"southwest" : HIVE "hive7",
    ])  );
}
