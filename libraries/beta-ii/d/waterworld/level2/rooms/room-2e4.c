/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_long(
   "A saltwater crocodile is lying in the seagrass here on the reef."
   " Most crocodiles stay in the aquifer, but saltwater crocodiles tend to prefer the cooler saltwater."
   " Their eating habits depend on the water temperature, warmer water means more activity."
   " This one seems to be dormant. It is ill-advised, however, to wander near the crocodile."
  );

  set_exits(([
    "northeast":ROOMS2"room-2f3.c",
    "northwest":ROOMS2"room-2d3.c",
    "southwest":ROOMS2"room-2d5.c",
    "southeast":ROOMS2"room-2f5.c"
   ]));
  set_items(([
    "crocodile":"Crocodiles can grow as large as 1,000 pounds and measure 12 feet in length."
    " It has 4 short legs and a very powerful tail."
    " Crocodiles have a 'nictitating membrane' or second eyelid that allows them to see underwater."
    " The bite of a crocodile can exceed 4,000 pounds per square inch."
    " Interestingly however, the muscles meant to open the mouth are fairly weak.",
    "aquifer":"The aquifer is the area at the mouth of a river or bay where salt and fresh water mix."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
