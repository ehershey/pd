#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "no teleport" : 1, "light" : 0, "night light" : 0]) );
set_smell("default", "The tunnel has a stagnant, stale stench to it.");
set_listen("default", "Echos near and far can be heard throughout the tunnels.");
set_short("venturing through tunnels");
set_long("The dark tunnels steer in many directions, hopelessly leading to nowhere. Specks of dirt float through the air, sticking to any sort of sweat or moisture. Shadows seem to dance in the darkness, and some look like they might have knives. A pile of bones rests lazily between two jagged rocks. A small puddle is being formed by the constant dripping of the ceiling.");
set_items(([
"dark" : "Although you can't see it, the darkness is very dark.",
"dirt" : "The dirt of the tunnels floats through the stagnant air.",
"ground" : "The ground covered in rocks and dirt, and looks fairly tricky to walk through.",
({"rock", "rocks"}) : "The rocks are jagged and large for the most part, and seem to make travel difficult.",
]));
set_exits(([ "north" : ROOMS "/darkandscary/15.c",
"east" : ROOMS "/darkandscary/19.c"]));
}

void reset() {
::reset();
if (!present("ogre 2")) {
new(MOBS+"ogre")->move(this_object());
new(MOBS+"greenogre")->move(this_object());
}
}

