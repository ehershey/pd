#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "The tunnel turns sharply.   "
         
    );
    set_items(([
        "tunnel" : "Deep underneath the Sabai Dessert.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"northeast" : NEST "nest4",
"east" : NEST "nest2",
    ])  );
}
