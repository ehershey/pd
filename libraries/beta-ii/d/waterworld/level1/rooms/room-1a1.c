/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
    ::create();
    set_properties((["water":1,"light":3,"night light":3]));
    set_listen("default","You hear the sounds of Tirun to the north.");

    set_long(
      "The foliage has completely blocked the passages to the west."
      " Several feet of razor sharp dune grass and small trees cover the passageways."
      " The beach extends to the east a good ways."
      " Tirun bay splashes onto the shoreline from the south."
    );
    set_exits(([
        "north":"/d/nopk/tirun/beach/1,1,0",
	"east":ROOMS1"room-1b1.c",
	"southeast":ROOMS1"room-1b2.c",
	"south":ROOMS1"room-1a2.c"
      ]));
    set_items(([
	"foliage":"Numerous plants of every shape and size.",
	"water":"The water seems to beckon to all who gaze upon it."
      ]));
    new(PEARLS"white_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
    ::reset();

    MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
}
