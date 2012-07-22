#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "Fresh straw has been laid down to make beds for the tired "
      "Raknid guards."
         
    );
    set_items(([
        "straw" : "It is made of grass, freshly dried.",
        "beds" : "It is made of fresh straw.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"east" : NEST "est63",
    ])  );
}
