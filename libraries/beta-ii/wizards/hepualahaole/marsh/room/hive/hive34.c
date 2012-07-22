#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "There is a bridge to the west. To the east is more tunnels."
         
    );
    set_items(([
        "tunnel" : "One of many in this place.",
        "bridge" : "It crosses over a deep ravine.",
        "ravine" : "It is so deep, all you see is total darkness.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"east" : HIVE "hive35",
"west" : HIVE "hive33",
    ])  );
}
