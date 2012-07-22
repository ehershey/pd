#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("desert",1);
    set_short("On a peaceful path");
    set_day_long(
      "A small volcano looking hill surrounded by palm trees, and a  "
      "small pool of water fills this mirage.  It appears the "
      "volcano holds a small fortress of some kind."
 
    );
    set_night_long(
      "A small volcano looking hill stands as high as the moon."
          );
    set_items(([
        "desert" : "Lots and lots of sand.",
        "fortress" : "It is made out of sand, with a frog pond inside.",
        "mirage" : "This one is the real thing.",
        "trees" : "Palm trees.",
            ]));
    set_listen("default", "Sounds of frogs croaking in the pond.");
    set_exits( ([
"down" : NEST "nest15",
"out" : SAB "sab24",
    ]) );
}
void reset() {
 ::reset();
   if (!present("raknid")) {
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
 
    }
}
