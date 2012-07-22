#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "On a very narrow path.  The path sits on rock that "
      "is embedded in the river.  "
      "There is no way down to the river from here, because "
      "of the sharp, jagged rocks.  The bridge is up ahead "
      "to the west.  Looking south across the water, there is "
      "a faint glimmer of torches that outlines a city."
     
    );
    set_items(([
        "path" : "It is very narrow, because the water has been "
                 "beating up against it for many moons now.",
        "rock" : "Kinda slippery from the moss growing on it.",
        "river" : "It sparkles under the torch light from the "
                  "bridge",
        "rocks" : "Hard to scale down these kind of rocks, it "
                  "is very sharp and jagged, like broken glass.",
        "bridge" : "It's a wooden bridge with many torches "
                   "lighting up the cavern.",
        "torches" : "Torches across the river seems to outline a "
                    "floating city.",
        "city" : "It seems to float in the middle of the river.",
        "water" : "The water sparkles under the torch light.",
        "cavern" : "You have no idea how big it is, darkness "
                   "absorbs the light.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"west" : HIVE "hve26",
"east" : HIVE "hve28",
    ])  );
}
