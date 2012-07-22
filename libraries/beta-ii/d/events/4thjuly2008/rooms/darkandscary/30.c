#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "no teleport" : 1, "light" : 0, "night light" : 0]) );
set_smell("default", "The tunnel has a stagnant, stale stench to it.");
set_listen("default", "Echos near and far can be heard throughout the tunnels.");
set_short("venturing through tunnels");
set_long("The dark tunnels are nearly invisible without a source of light. A pile of bones rests lazily between two jagged rocks. The sound of scurrying feet echoes off the walls. A dark rock falls from the ceiling, causing a thump that carries throughout the tunnels. A small puddle is being formed by the constant dripping of the ceiling.  This appears to be a dead end.");
set_items(([
"dark" : "Although you can't see it, the darkness is very dark.",
"dirt" : "The dirt of the tunnels floats through the stagnant air.",
"ground" : "The ground covered in rocks and dirt, and looks fairly tricky to walk through.",
({"rock", "rocks"}) : "The rocks are jagged and large for the most part, and seem to make travel difficult.",
]));
set_exits(([ "south" : ROOMS "/darkandscary/final.c",
"northeast" : ROOMS "/darkandscary/29.c"]));
}

void reset() {
::reset();
if (!present("ogre")) {
new(MOBS+"ogremage2")->move(this_object());
}
}

