/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_long(
   "A school of barracuda have corralled a school of cod into the shallow waters between the reef and the sandbars."
   " The barracudas are picking off the cods one by one as they get hungry."
   " Barracudas feed upon almost any fish that is smaller or the same size as they are."
  );

  set_exits(([
    "southeast":ROOMS2"room-2g4.c",
    "southwest":ROOMS2"room-2e4.c",
    "northwest":ROOMS2"room-2e2.c"
   ]));
  set_items(([
    "barracuda":"An average barracuda is about 30 pounds and measures about 2 feet."
    " They have long slender bodies with long needle-like jaws."
    " Usually, they will not attack things larger than themselves unless they feel threatened."
    " Barracudas are most dangerous in schools due to the fact that they tend to 'swarm' their prey and kill anything and everything in their path."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
