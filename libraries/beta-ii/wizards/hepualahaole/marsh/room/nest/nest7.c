#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Headquarters");
    set_long(
      "The Raknid's Headquarters is located here. There are weapons "
      "of all sorts lined up against the walls, ready to be used, to "
      "defend the nest."
         
    );
    set_items(([
        "headquarters" : "It is placed just before the main entrance of "
                         "the nest",
        "weapons" : "They are arranged along the walls, sticks to swords.",
        "walls" : "Lots of weapons are lined up, waiting to be used.",
        "nest" : "It's where the Raknids live.",
        "sticks" : "Very primitive, but effective.",
        "swords" : "Double-edged swords with a spider design engraved in "
                   "the blade.",
        "design" : "Picture of a Raknid engaging in battle.",
        "spider design" :  "Picture of a Raknid engaging in battle.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"east" : NEST "nest8",
    ])  );
}
void reset() {
 ::reset();
    if (!present("raknid")) {
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
 
    }
}
