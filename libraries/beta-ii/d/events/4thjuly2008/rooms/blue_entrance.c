#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "no teleport" : 1, "light" : 1, "night light" : 1]) );
set_property("entrance_room", "/d/inferi_island/marshes/rooms/marsh_5");
set_smell("default", "The tunnel has a smokey, burning smell to it.");
set_listen("default", "The bubbling of lava can be heard throughout the tunnels.");
set_short("venturing through tunnels");
set_long("The molten tunnels steer in many directions, leading to nowhere in a %^RED%^%^BOLD%^heated %^RESET%^daze. The air is composed of a stiffling mixture of heat and sulfur. Heat and smoke makes traveling the tunnels dangerous. The bubbling of %^RED%^l%^BOLD%^a%^YELLOW%^v%^RED%^a%^RESET%^ echoes off the walls. All of the air seems to vibrate in the waves of heat.");
set_items(([
"lava" : "There is a pool of lava on either side of you.",
"smoke" : "Wisps of smoke float through the air..",
"ground" : "The ground beneath you is a very hot looking rock path, surrounded by pools of lava..",
({"rock", "rocks"}) : "The path below you is made of rocks..",
]));
set_exits(([
//  "out" : query_property("entrance_room"),
  "north" : ROOMS "/moltenlava/19.c",
]));
add_pre_exit_function("out", "checkmob");
}

int checkmob() {
  if (!this_player()->is_player() && !this_player()->is_pet()) return 0;
  return 1;
}
