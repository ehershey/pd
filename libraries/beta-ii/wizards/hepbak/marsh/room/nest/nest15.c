#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest Entrance");
    set_long(
      "Inside a long dark tunnel.  The walls are made from a mixture of sand "
      "and a sticky substance.  It appears to be the nest of fearless "
      "creatures, otherwise known as Raknids."
         
    );
    set_items(([
       "tunnel" : "It's dark inside, but there is light streaming in from "
                   "outside.",
       "walls" : "It is made from a mixture of sand and a sticky substance.",
       "substance" : "It appears to be regurgitated sand.",
       "sticky substance" : "It appears to be regurgitated sand.",
       "nest" : "It has all the inner workings of a hive-minded race.",
       "sand" : "By itself, it's not a very good choice for building tunnels, "
                 "but regurgitated sand makes it tougher then dry mud.", 
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"south" : NEST "nest13",
"out" : FORT "mirage",
    ])  );
}
void reset() {
 ::reset();
   if (!present("raknid")) {
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
 
    }
}
