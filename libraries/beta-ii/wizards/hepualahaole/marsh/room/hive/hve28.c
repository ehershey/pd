#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "The tunnel opens up into a huge cavern.  To the north, "
      "there is a path leading on a downward slope.  Up ahead "
      "to the east, lies a wooden bridge with torches shining "
      "brightly.  To the south, there is a very steep, rocky "
      "cliff which, looking down, plunges into the river.  "
      "Looking over the river, a faint glimmer of torches "
      "outlines a city."
     
    );
    set_items(([
        "tunnel" : "Is to the east.",
        "cavern" : "There seems to be no ceiling.",
        "path" : "It goes down a slope.",
        "slope" : "Not too steep.",
        "bridge" : "It's is made out of wood, and it " 
                   "crosses over the river.",
        "wood" : "The kind that creaks when someone walks "
                 "across it.",
        "torches" : "It lights up the cavern.",
        "rock" : "Unlike the tunnels, this is rock.",
        "cliff" : "It almost makes you feel dizzy looking down.",
        "river" : "It sparkles under the light of the torches.",
        "outline" : "There is a city in the middle of the river.",
        "city" : "It seems to be floating in the middle of the "
                 "river.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"west" : HIVE "hve27",
"east" : HIVE "hve29",
"north" : HIVE "hve17",
    ])  );
}
void reset() {
 ::reset();
     if (!present("raknid")) {
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
    }
}
