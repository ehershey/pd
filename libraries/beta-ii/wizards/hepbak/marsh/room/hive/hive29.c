#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "There's a bridge to the east, and a dark tunnel leading southwards.  "
      "A light can be seen in the southern direction. "
     
    );
    set_items(([
        "tunnel" : "It runs in a diagonal direction, and not used recently.",
        "light" : "It's off in a distance.",
        "bridge" : "It crosses over a deep ravine.",
        "ravine" : "If you listen carefully, you can hear trickling water.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"east" : HIVE "hive30",
"southwest" : HIVE "hive26",
    ])  );
}
