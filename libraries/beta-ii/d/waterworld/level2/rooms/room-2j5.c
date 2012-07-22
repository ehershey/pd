/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_long("The reef is covered with sea anemones, tube worms, sea urchins, and fish."
   " There is a small cavern just below this section of the reef that seems to be the home of a sea turtle."
   " Some of the tube worms are feeding on the crawfish that swim too close to them."
  );
  add_invis_exit("cavern");
  set_exits(([
    "cavern":ROOMS2"secret-3a.c",
    "northeast":ROOMS2"room-2k4.c",
    "southeast":ROOMS2"room-2k6.c",
    "northwest":ROOMS2"room-2i4.c",
    "southwest":ROOMS2"room-2i6.c"
   ]));
  set_items(([
    "turtle":"It is a very large green sea turtle. The shell appears to be quite strong as do its legs.",
    "cavern":"A very large cavern in the seabed. It is quite large and inviting."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
