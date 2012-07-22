#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's sleeping quaters");
    set_long(
      "Sleeping quarters set aside for the guards. There are "
      "two straw beds on the floor."
         
    );
    set_items(([
        "quaters" : "A small room with four walls.",
        "sleeping quaters" : "A small room with four walls.",
        "beds" : "Made of fresh straw.",
        "straw" : "Dried out grass.",
        "floor" : "Two beds of straw is placed on the floor.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"southwest" : NEST "nest9",
    ])  );
}
