#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "no teleport" : 1, "night light" : 1]) );
set_smell("default", "The tunnel has a fresh and frozen smell to it.");
set_listen("default", "Echos near and far can be heard throughout the chilly tunnels.");
set_short("venturing through icy tunnels");
set_long("The icy tunnels hopelessly slip and slide in many directions. The air is composed of a fresh mixture of %^BOLD%^cold%^RESET%^ and clean. An %^BOLD%^%^CYAN%^icy%^RESET%^ pile of bones shivers lazily between two frozen rocks. Flakes of %^BOLD%^snow%^RESET%^ float through the air, sticking to any dry surfaces. There is a large torch hanging on the wall, burning through the %^BOLD%^%^CYAN%^ice%^RESET%^ and showing gravel.");
set_items(([
"ice" : "Whether the sheets, boulders of, or icicles - ice covers this entire area.",
"snow" : "The ground is covered in a thin layer of snow..",
"walls" : "The walls have an occasional torch, burning through blue ice to see blue rock.",
({"rock", "rocks"}) : "The rocks are all frozen, and have turned a bluish color.",
]));
set_exits(([ "northeast" : ROOMS "/icystuff/19.c",
"west" : ROOMS "/icystuff/25.c",
"southeast" : ROOMS "/icystuff/23.c"]));
}

void reset() {
::reset();
if (!present("ogre 3")) {
new(MOBS+"ogremonk")->move(this_object());
new(MOBS+"ogremonk")->move(this_object());
new(MOBS+"ogremonk")->move(this_object());
}
}

