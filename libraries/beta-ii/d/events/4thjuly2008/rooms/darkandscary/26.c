#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "no teleport" : 1, "light" : 0, "night light" : 0]) );
set_smell("default", "The tunnel has a stagnant, stale stench to it.");
set_listen("default", "Echos near and far can be heard throughout the tunnels.");
set_short("venturing through tunnels");
set_long("The dark tunnels are nearly invisible without a source of light. The air is composed of a sickening mixture of humid and stale. There is a small cave in the wall, fresh with signs of use. Shadows seem to dance in the darkness, and some look like they might have knives. Darkness makes traveling the tunnels dangerous.");
set_items(([
"dark" : "Although you can't see it, the darkness is very dark.",
"dirt" : "The dirt of the tunnels floats through the stagnant air.",
"ground" : "The ground covered in rocks and dirt, and looks fairly tricky to walk through.",
({"rock", "rocks"}) : "The rocks are jagged and large for the most part, and seem to make travel difficult.",
]));
set_exits(([ "southwest" : ROOMS "/darkandscary/25.c",
"east" : ROOMS "/darkandscary/27.c"]));
}

void reset() {
::reset();
if (!present("ogre 2")) {
new(MOBS+"bigogre")->move(this_object());
new(MOBS+"ogre")->move(this_object());
}
}

