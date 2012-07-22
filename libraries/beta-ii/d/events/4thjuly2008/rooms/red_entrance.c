#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "no teleport" : 1, "light" : 1, "night light" : 1]) );
set_property("entrance_room", "/d/roston/rooms/roston42");
set_smell("default", "The tunnel has a fresh and frozen smell to it.");
set_listen("default", "Echos near and far can be heard throughout the chilly tunnels.");
set_short("venturing through icy tunnels");
set_long("The icy tunnels slip through many directions, sliding to nowhere. The sound of dripping %^BOLD%^%^BLUE%^water%^RESET%^ echoes off the walls. Slipperiness makes traveling the tunnels dangerous. There is a strong sense of cleanliness here. The ground is covered in %^BOLD%^frozen%^RESET%^ stones of different sizes, scattered randomly throughout the %^BOLD%^snow%^RESET%^.");
set_items(([
"ice" : "Whether the sheets, boulders of, or icicles - ice covers this entire area.",
"snow" : "The ground is covered in a thin layer of snow..",
"walls" : "The walls have an occasional torch, burning through blue ice to see blue rock.",
({"rock", "rocks"}) : "The rocks are all frozen, and have turned a bluish color.",
]));
set_exits(([
  "west" : ROOMS "/icystuff/15.c",
//  "out" : query_property("entrance_room"),
]));
add_pre_exit_function("out", "checkmob");
}

int checkmob() {
  if (!this_player()->is_player() && !this_player()->is_pet()) return 0;
  return 1;
}

