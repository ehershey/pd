#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "no teleport" : 1, "night light" : 1]) );
set_smell("default", "The tunnel has a fresh and frozen smell to it.");
set_listen("default", "Echos near and far can be heard throughout the chilly tunnels.");
set_short("venturing through icy tunnels");
set_long("The icy tunnels hopelessly slip and slide in many directions. The sound of dripping %^BOLD%^%^BLUE%^water%^RESET%^ echoes off the walls. An %^BOLD%^%^CYAN%^icy%^RESET%^ pile of bones shivers lazily between two frozen rocks. The air is composed of a fresh mixture of %^BOLD%^cold%^RESET%^ and clean. Flakes of %^BOLD%^snow%^RESET%^ float through the air, sticking to any dry surfaces.");
set_items(([
"ice" : "Whether the sheets, boulders of, or icicles - ice covers this entire area.",
"snow" : "The ground is covered in a thin layer of snow..",
"walls" : "The walls have an occasional torch, burning through blue ice to see blue rock.",
({"rock", "rocks"}) : "The rocks are all frozen, and have turned a bluish color.",
]));
set_exits(([ "southwest" : ROOMS "/icystuff/4.c",
"northeast" : ROOMS "/icystuff/12.c",
"northwest" : ROOMS "/icystuff/6.c"]));
}

void reset() {
::reset();
if (!present("ogre 2")) {
new(MOBS+"ogre")->move(this_object());
new(MOBS+"ogrethug")->move(this_object());
}
}

