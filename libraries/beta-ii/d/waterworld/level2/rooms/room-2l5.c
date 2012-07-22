/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_listen("default","The sounds of a manatee fills the area.");
  set_long("A family of manatees has settled into a small cavern in the reef."
   " Several baby manatees are located in the small cave as well."
   " The manatees appear to be dining on several versions of aquatic plants that have taken root on this part of the reef."
   "\nThe water is unusually warm here for some reason.\n"
  );
  set_exits(([
    "northeast":ROOMS2"room-2m4.c",
    "northwest":ROOMS2"room-2k4.c",
    "southwest":ROOMS2"room-2k6.c"
   ]));
  set_items(([
    "manatee":"A manatee is also known as a 'sea cow'. They are attracted by warm water and tend to set up their homes any place where the water is at least 75 F and the food supply is plentiful. They mostly eat plants and coral. This reef is perfect for them. The manatee is part of the genus of animals known as Trichechus.",
    "cave":"Seems some careless mage left a collection of stones in the back of the cave. That would explain why the water is warm and why the manatees are here.",
    "babies":"Awww, they're so cute.  Baby manatees are called cubs."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
