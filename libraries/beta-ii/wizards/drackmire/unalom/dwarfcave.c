
#include <std.h>
#include "unalom.h"

inherit ROOM;
void create() {
    ::create();
    set_property("night light", 1);
    set_property("light", 1);
    set_short("a cave");
    set_long("This is a small cave in the side of cliffs, probably "
    "used for excavation.  A small fire sits in the middle of the room "
    "providing the only light in the cave.  The fire dancing causes the "
    "iridescent walls of the cave to come alive, as though creatures "
    "were living in the walls."
      );
    set_listen("default", "The wind howls outside.");
    set_smell("default", "The air smells of smoke from the fire");
    set_exits( ([ "out" : UNAROOM"cliffledge",]) );
    set_items(
        (["shadows" : "As you look at one of the shadows, it seems to "
        "run away, evading your gaze",
          "fire" : "A small campfire made to keep someone warm."]  ) );
}

void reset() {
  ::reset();
  if(!present("miner"))
    new(UNAMON"miner1.c")->move(this_object());
    }
