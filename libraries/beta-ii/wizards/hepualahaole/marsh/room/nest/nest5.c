#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "The tunnel rounds off southwest, leading deeper into the "
      "nest. To flee the nest, go east.",         
    );
    set_items(([
        "tunnel" : "Going one way leads you deeper, go another way takes you
out.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"east" : NEST "nest6",
"southwest" : NEST "nest3",
    ])  );
}
