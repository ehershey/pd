#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "Inside a very dark tunnel. "
     
    );
    set_items(([
        "tunnel" : "It is very dark in here.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"northwest" : HIVE "hve30",
"southeast" : HIVE "hve35",
    ])  );
}
