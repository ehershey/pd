/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

int swim_to_reef(string str);

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_listen("default","You hear the sound of a lighthouse's foghorn in the distance.");
  set_smell("default","It smells like rotting fish.");
  set_long("Several half-eaten fish float on the water here. A couple of small sharks seem to be circling. There seems to be a reef of some kind in the distance.");

  set_exits(([
    "east":ROOMS1"room-1f7.c",
    "north":ROOMS1"room-1e6.c",
    "west":ROOMS1"room-1d7.c"
   ]));
  set_items(([
    "dead fish":"It's a dead fish.  < Do you REALLY want a more graphic description?? >",
    "reef":"It seems to be a section of Tirun's Barrier Reef. Perhaps you can swim out to it??",
    "water":"The water is mixed with half-eaten fish parts and blood..."
   ]));
  new(PEARLS"black_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
}

void init() {
  ::init();
  add_action("swim_to_reef", "swim");
}

int swim_to_reef(string str) {
  object tp = this_player();
  if (!str) return 0;
  switch (str) {
  case "reef": case "to reef": case "out to reef":
  case "to the reef": case "out to the reef":
//    message("info", "You try to swim out to the reef, but a wave pushes you back.", tp);
    tp->move_player(ROOMS2"room-2h2", "to the reef");
    return 1;
    break;
  default:
    return 0;
  }
  return 0;
}
