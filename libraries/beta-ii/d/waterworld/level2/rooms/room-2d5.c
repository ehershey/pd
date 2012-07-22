/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_long(
   "A collection of porgies are eating the crustaceans and shellfish in this section of the reef."
   " Some of the porgies are bunting the shellfish and crustaceans off of the reef."
   " Once it manages to jolt one free, a porgy catches it in its specially adapted jaws and crushes it with ease."
  );

  set_exits(([
    "northeast":ROOMS2"room-2e4.c",
    "southeast":ROOMS2"room-2e6.c",
    "southwest":ROOMS2"room-2c6.c",
    "northwest":ROOMS2"room-2c4.c"
   ]));
  set_items(([
    "porgy":"The porgy is a member of the sparidae family."
    " They are the natural predator of most shellfish, clams and crustaceans."
    " Their jaws are specially adapted for crushing the shells of their prey."
    "\n\nUnfortunately for the porgies, they are considered quite a delicious fish by most other animals, including humans."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
