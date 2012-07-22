#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "A restful atmosphere fills the air.  This kind of room "
      "exists all across the nest.  It's not a sleeping room, "
      "it is more of a social room, or a meditation room."
         
    );
    set_items(([
        "room" : "Ten full-sized Raknids can occupy this room.",
        "nest" : "It is the Raknid's home.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"east" : NEST "est72",
    ])  );
}
void reset() {
 ::reset();
     if (!present("raknid")){ 
    new(MOB"rshovel")->move(this_object());
     if (!present("raknid")) 
    new(MOB"rpick")->move(this_object());
    }
}
