#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "There are vials of scented oils scattered all over the "
      "place.  A bed of straw is placed in a corner where little "
      "light shines on it.  It's a home of a working cleric."
         
    );
    set_items(([
        "vials" : "There are so many, they all don't fit on the shelves",
        "oils" : "They are all scented, some soothing, others vile.",
        "scented oils" : "Some smell soothing, while others don't.",
        "bed" : "It is placed in the corner, where not much light reaches "
                "it.  It's to help speed up the process of the oils.",
        "straw": "It is fresh dried grass, lined with a sweet smelling "
                 "oil, might be rosemary.",
        "corner" : "A bed is placed there.",
        "home" : "As far as Raknid's homes go, this is pretty well "
                 "decorated.  If you call vials decoration that is.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"southeast" : NEST "est68",
    ])  );
}
void reset() {
 ::reset();
   if (!present("raknid")) {
      new(MOB"rcleric")->move(this_object());
 
    }
}
