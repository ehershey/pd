/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_listen("default","The soft sound of bubbles popping can be heard.");
//  set_listen("bubbles","You have traced the sound of the bubbles to a hidden crack in the ocean floor.  It is big enough for you to enter.");
  set_long("Several dozen emerald crabs are feeding on the algae and coral."
   " They cling very easily to the rockface of the reef and move fairly slowly."
   " Unfortunately for the crabs, the larger fish consider them as much a delicacy as they do the coral."
  );

  set_exits(([
//    "crack":ROOMS2"secret-5.c",
    "northwest":ROOMS2"room-2a4.c",
    "northeast":ROOMS2"room-2c4.c",
    "southeast":ROOMS2"room-2c6.c"
   ]));
  set_items(([
    "bubbles":"They seem to be coming from someplace near the ocean floor.",

//    "crack":"It seems you can squeeze into the opening.",
    "crabs":"The emerald crab is a natural scavenger. They feed on any dead animal matter as well as coral and algae.",
    "rockface":"The rear legs of the emerald crab are ideally evolved for gripping the rocks. Most of the 'rocks' here are fossilized coral remains."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
