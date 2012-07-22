#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1 ]));
  set_short("Dragon Lands North");
  set_day_long("This is the furthest northeast point of the mountain which lies to the south. The path along the ridge to the south connects to a larger mass of mountain, which climbs steadily upward, between two large rock gateways into the greater core of the mountain. The northeastern part of the mountain ridge peaks before a great vantage point of the rest of the island below, which is covered with untended greenery.");
  set_night_long("This is the furthest northeast point of the mountain which lies to the south. The path along the ridge to the south connects to a larger mass of mountain, which climbs steadily upward, between two large rock gateways into the greater core of the mountain. The northeastern part of the mountain ridge peaks before a great vantage point of the rest of the island below, which is infested with warring shadows that twist and snarl at each other in the steady glow of the moonlight. A cool night breeze blows across the mountain ridge, swept upwards from the land below.");
  set_exits( ([
    "northwest" : DRAG_ROOMS"dragnorth07.c",
    "south" : DRAG_ROOMS"dragnorth11.c",
             ]) );
  set_items( ([
    ({ "gateway", "gateways" }) : "Two large rock structures are on either side of the path. They serve as a symbolic gateway into the dragon lands.",
             ]) );
}
