/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_long("It appears that several shrimp have made their homes inside the sea anemones in this area."
   " A handful of shad are swimming around here trying to eat the shrimps."
   " The symbiotic relationship between the shrimp and sea anemone is pure poetry in motion."
   " The shrimp clean the anemone of bactieria while the anemone's poisonous tentacles keep the fish at bay for the shrimps.");

  set_exits(([
    "northwest":ROOMS2"room-2k2.c",
    "southwest":ROOMS2"room-2k4.c",
    "southeast":ROOMS2"room-2m4.c"
   ]));
  set_items(([
    "shrimp":"He's busy eating all the bacteria off of the sea anemone.",
    "anemone":"Its stingers are doing an excellent job of keeping the shad away from the shrimps.",
    "shad":"It's a small silver fish that loves to eat shrimp. It seems to be out of luck today, though.",
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
