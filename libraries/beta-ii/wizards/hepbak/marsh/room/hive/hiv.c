#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":1, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "On the island in the middle of the river.  Torches "
      "are set along the beach, and at the foot of a path "
      "that leads inward.  There is no way back up to the "
      "ledge of the glowing tree." 
     
    );
    set_items(([
        "island" : "It is in the middle of the river.",
        "river" : "It is underneath the desert, in the "
                  "middle of the nest.",
        "torches" : "The are all along the outside of the "
                    "island.  Also, two torches light the "
                    "foot of the path leading inwards.",
        "path" : "It leads towards the middle of the island.",
        "ledge" : "It is high above you.",
        "glowing tree" : "It glows up on top of the ledge.",
        "tree" : "It glows up on top of the ledge.",
  
    ]));
    set_exits( ([
"east" : HIVE "hiv2",
    ])  );
}
void reset() {
 ::reset();
     if (!present("raknid")){ 
    new(MOB"r_guard")->move(this_object());
    new(MOB"r_guard")->move(this_object());
    }
}
