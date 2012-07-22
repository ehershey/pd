/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_long("The reef has several large butterfly fish floating near it."
   " A couple of nudibranchs are slinking across the corals."
   " There's a disturbance near one of the sea anemones."
   " Seems some butterfly fish chose an anemone that was home to some clown fish to try and eat.");

  set_exits(([
    "northeast":ROOMS2"room-2k2.c",
    "northwest":ROOMS2"room-2i2.c",
    "southeast":ROOMS2"room-2k4.c",
    "southwest":ROOMS2"room-2i4.c"
   ]));
  set_items(([
    "butterfly fish":"A small breed of fish that eats sea anemones.",
    "nudibranchs":"This is a type of slug that eats squirts, sponges and plankton. Most breeds are highly poisonous.",
    "fight":"It seems some butterfly fish are getting attacked by some anemone fish.",
    "anemone fish":"These fish (also known as clown fish) live in a symbiotic state with the sea anemones.  They protect the sea anemones from predators like the butterfly fish. The sea anemone protects the clown fish's young with its poisonous tentacles."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
