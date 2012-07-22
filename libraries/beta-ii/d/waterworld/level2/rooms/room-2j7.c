/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_smell("default","The strong stench of mold fills the area.");
  set_long("Whole sections of the reef here appear to be under attack by a fungus."
   " The mushrooms seem to be feeding on the corals and plants here."
   " Most versions of fungi are microscopic but others, such as these mushrooms are macroscopic in scale."
   " The smaller fish seem to be dining on the mushrooms in turn."
  );

  set_exits(([
    "northeast":ROOMS2"room-2k6.c",
    "northwest":ROOMS2"room-2i6.c"
   ]));
  set_items(([
    "mushrooms":"This is a prime example of underwater mushrooms."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
