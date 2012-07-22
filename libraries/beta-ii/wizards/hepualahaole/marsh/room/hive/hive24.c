#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "It's very busy in here.  Guards work very hard at "
      "keeping intruders out of thier newly formed nest."
         
    );
    set_items(([
        "nest" : "It's what the Raknids call home.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"northwest" : HIVE "hive27",
    ])  );
}
