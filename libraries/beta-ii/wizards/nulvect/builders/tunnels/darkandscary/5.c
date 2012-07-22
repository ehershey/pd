#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 0, "night light" : 0]) );
set_smell("default", "The tunnel has a stagnant, stale stench to it.");
set_listen("default", "Echos near and far can be heard throughout the tunnels.");
set_short("venturing through tunnels");
set_long("The dark tunnels hopelessly twist and turn in many directions. There is a small cave in the wall, fresh with signs of use. A pile of bones rests lazily between two jagged rocks. Specks of dirt float through the air, sticking to any sort of sweat or moisture. A small puddle is being formed by the constant dripping of the ceiling.");
set_items(([
"dark" : "Although you can't see it, the darkness is very dark.",
"dirt" : "The dirt of the tunnels floats through the stagnant air.",
"ground" : "The ground covered in rocks and dirt, and looks fairly tricky to walk through.",
({"rock", "rocks"}) : "The rocks are jagged and large for the most part, and seem to make travel difficult.",
]));
set_exits(([ "northeast" : ROOMS "/darkandscary/3.c",
"west" : ROOMS "/darkandscary/4.c"]));
}
