#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":1, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "The wooden bridge spans across the river joining "
      "tunnels within the nest.  What looked like torches "
      "from afar, is now magical balls of light floating "
      "just above the bridge.  Looking south, an outline "
      "of a floating city, shimmers in and out of sight."
     
    );
    set_items(([
        "wood" : "The wood looks to be very old and worn.",
        "bridge" : "It is made of wood and spans across "
                   "the river.  It has two railings on "
                   "either side of you to prevent you from "
                   "falling off.",
        "river" : "It sparkles under the magical light.",
        "light" : "It lights up the bridge and the cavern.",
        "magical balls" : "It floats a couple inches off the "
                          "bridge, and it seems to have no "
                          "substance to it, just mist.",
        "balls" : "It floats a couple inches off the "
                          "bridge, and it seems to have no "
                          "substance to it, just mist.",
        "outline" : "There are torches on the shores of the "
                    "floating city.",
        "city" : "It is in the middle of the river to the "
                 "south, it glimmers in and out of sight. so "
                 "you can't get a good look at it.",
        "mist" : "It feels cool to the skin.",
        "railings" : "Made of wood also, it's there to prevent "
                     "you from falling off.",
  
    ]));
    set_listen("default", "Sounds of trickling water.");
    set_exits( ([
"west" : HIVE "hve23",
"east" : HIVE "hve25",
    ])  );
}
