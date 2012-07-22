/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_long(
   "A large portion of the reef is under attack here by some crown-of-thorns starfish."
   " The starfish place themselves over a section of coral, release digestive enzymes and then absorb the nutrients."
   " Other than the nudibranch, this is one of the few animals that prey upon corals and sponges."
   " Luckily for the corals, there are also some triton trumpets dining on the starfish."
  );
  set_exits(([
    "northeast":ROOMS2"room-2c2.c",
    "southeast":ROOMS2"room-2c4.c",
    "southwest":ROOMS2"room-2a4.c"
   ]));
  set_items(([
    "crown-of-thorns":"This breed of starfish have as many as 20 arms covered with toxin spikes."
    " The spikes venom is an anti-coagulant causing severe painful wounds that take a long time to heal."
    " These starfish are the most destructive natural predator of corals.",
    "triton trumpets":"This large breed of snail is one of few predators of the crown-of-thorns starfish."
    " They paralyze them with a neuro-toxin present in their saliva."
    " They grow up to 24 inches in length and possess a hard shell."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
