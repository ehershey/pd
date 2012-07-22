#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "The downward slope continues to the west, leading deeper into "
      "the nest.  The tunnel going east, leads the way out."
         
    );
    set_items(([
        "slope" : "It seems to be a course adjustment, nothing spectacular.",
        "nest" : "It is the home of the Raknids.",
        "tunnel" : "Nothing but a ceiling, floor and two walls directing you.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"east" : NEST "nest3",
"west" : NEST "nest",
    ])  );
}
void reset() {
 ::reset();
    if (!present("raknid")) {
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
 
    }
}
