#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "There is a noticeable downward slope to the west, leading "
      "deeper inside the nest.  The tunnel rounds off to the northeast "
      "creating a blind spot to what may be on the other side."
         
    );
    set_items(([
        "slope" : "It seems to be a course adjustment, nothing spectacular.",
        "nest" : "It is the home of the Raknids.",
        "tunnel" : "It rounds off to the northeast, creating a blind spot.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"northeast" : NEST "nest5",
"west" : NEST "nest2",
    ])  );
}
