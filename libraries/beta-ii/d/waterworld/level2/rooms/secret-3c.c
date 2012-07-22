/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_listen("default","You hear dripping water.");
  set_smell("default","It smells like decay and mildew.");
  set_long("This is Pelican Pete's storage room."
   " There isn't much in here but barrels and barrels of alcohol."
   " There are some cases of pineapples and glasses in one corner."
  );

  set_exits(([
    "out":ROOMS2"secret-3b.c"
   ]));
  set_items(([
    "barrels":"These are barrels of almost every form of alcohol known to man (or pelican).",
    "cases":"The cases have many different forms of produce in them."
   ]));
  new(PEARLS"blood_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
