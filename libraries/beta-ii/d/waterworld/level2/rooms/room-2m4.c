/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_long("A conger eel has made its home in between some of the corals."
   " A couple of finger corals have taken root in this location."
   " There are also some fossilized corals at the bottom of the reef.");

  set_exits(([
    "northwest":ROOMS2"room-2l3.c",
    "southwest":ROOMS2"room-2l5.c"
   ]));
  set_items(([
    "conger eel":"This is a specimen of eel. He has a thick body and a tapered snout.",
    "finger coral":"This version of coral has developed an exoskeleton.",
    "fossilized coral":"This is the final form that coral takes after it dies. The calcium inside the coral solidifies and turns into chalk."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
