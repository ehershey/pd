#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "The tunnel leads deeper into the nest going west.  To flee "
      "from the nest, going north-bound will do the trick."
         
    );
    set_items(([
        "tunnel" : "It's a long one.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"north" : NEST "nest10",
"west" : NEST "nest5",
    ])  );
}
void reset() {
 ::reset();
    if (!present("raknid")) {
      new(MOB"r_guard")->move(this_object());
 
    }
}
