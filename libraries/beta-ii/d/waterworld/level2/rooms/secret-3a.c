/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_smell("default","Sweet smelling fumes are drifting through the cavern.");
  set_smell("fumes","The fumes are originating from a crack in the wall. They smell a bit like pina colada.");
  set_long("This cavern looks to be the home of a large sea turtle."
   " The walls seem to have been drilled or blasted out of the bedrock.");
  add_invis_exit("hole");
  set_exits(([
    "south":ROOMS2"room-2j5.c",
    "hole":ROOMS2"secret-3b.c"
   ]));
  set_items(([
    "crack":"There is a hole here you might be able to squeeze into."
   ]));
  new(PEARLS"rose_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
