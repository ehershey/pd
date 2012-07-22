/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_listen("default","You hear the sound of wood breaking nearby.");
  set_listen("default","There is a strong scent of mildew in the air.");
  set_long("A gigantic barrier reef sits here."
   " There are countless lifeforms present around the reef."
   " Several sea anenomes, coral, fish and plants can be seen from this location."
   " The main part of the bay can be seen to the north."
  );

  set_exits(([
    "east":ROOMS2"room-2i2.c",
   ]));
  set_items(([
    "bay" : "You can swim back to it from here.",
    "coral":"These expansive, hard structures are actually animals.",
    "sea anenomes":"These animals have tentacles that grab food and sweep it into their body cavities.",
    "plants":"Multiple forms of algae and plankton are floating around here.",
   ]));
  new(PEARLS"black_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
int swim_bay(string str) {
  object tp = this_player();
  if (!tp || !str) return 0;
  switch (str) {
    case "bay": case "to bay": case "to the bay":
    case "back to bay": case "back to the bay":
      tp->move_player(ROOMS1"room-1e7", "back to the bay");
      return 1;
    break;
    default:
      return 0;
  }
  return 0;
}
void init() {
  ::init();
  add_action("swim_bay", "swim");
}

