#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 0, "night light" : 0]) );
set_smell("default", "The tunnel has a stagnant, stale stench to it.");
set_listen("default", "Echos near and far can be heard throughout the tunnels.");
set_short("venturing through tunnels");
set_long("The dark tunnels steer in many directions, hopelessly leading to nowhere. A dark rock falls from the ceiling, causing a thump that carries throughout the tunnels. The air is composed of a sickening mixture of humid and stale. There is a strong sense of stagnancy here. Footprints can be seen below, heading in all directions.");
set_items(([
"dark" : "Although you can't see it, the darkness is very dark.",
"dirt" : "The dirt of the tunnels floats through the stagnant air.",
"ground" : "The ground covered in rocks and dirt, and looks fairly tricky to walk through.",
({"rock", "rocks"}) : "The rocks are jagged and large for the most part, and seem to make travel difficult.",
]));
set_exits(([ "northeast" : ROOMS "/darkandscary/21.c",
"southeast" : ROOMS "/darkandscary/24.c"]));
}
