#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "no teleport" : 1, "light" : 0, "night light" : 0]) );
set_smell("default", "The tunnel has a stagnant, stale stench to it.");
set_listen("default", "Echos near and far can be heard throughout the tunnels.");
set_short("venturing through tunnels");
set_long("The dark tunnels hopelessly twist and turn in many directions. A small puddle is being formed by the constant dripping of the ceiling. There is a strong sense of stagnancy here. Shadows seem to dance in the darkness, and some look like they might have knives. The ground is covered in jagged stones of different sizes, scattered randomly throughout the dirt.");
set_items(([
"dark" : "Although you can't see it, the darkness is very dark.",
"dirt" : "The dirt of the tunnels floats through the stagnant air.",
"ground" : "The ground covered in rocks and dirt, and looks fairly tricky to walk through.",
({"rock", "rocks"}) : "The rocks are jagged and large for the most part, and seem to make travel difficult.",
]));
set_exits(([ "east" : ROOMS "/darkandscary/5.c",
"southeast" : ROOMS "/darkandscary/6.c"]));
}

void reset() {
::reset();
if (!present("ogre")) {
new(MOBS+"ogremage")->move(this_object());
}
}

