#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "Deeper inside the nest, there is hardly any natural source of light.  "
      "The tunnel veers off to the southwest.  To exit the nest, going north "
      "will lead the way."   
    );
    set_items(([
        "nest" : "Built by the Raknids.",
        "light" : "It's not completely dark, but it isn't well lit either.",
        "tunnel" : "It winds around the nest, in an orderly fashion.",
          
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"southwest" : NEST "nest10",
"north" : NEST "nest15",
    ])  );
}
