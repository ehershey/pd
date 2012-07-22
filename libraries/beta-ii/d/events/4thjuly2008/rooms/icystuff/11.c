#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "no teleport" : 1, "night light" : 1]) );
set_smell("default", "The tunnel has a fresh and frozen smell to it.");
set_listen("default", "Echos near and far can be heard throughout the chilly tunnels.");
set_short("venturing through icy tunnels");
set_long("The icy tunnels hopelessly slip and slide in many directions. There is a large torch hanging on the wall, burning through the %^BOLD%^%^CYAN%^ice%^RESET%^ and showing gravel. The sound of dripping %^BOLD%^%^BLUE%^water%^RESET%^ echoes off the walls. Footprints can be seen in the %^BOLD%^snow%^RESET%^, heading in all directions. A large %^BOLD%^i%^RESET%^%^BLUE%^c%^RESET%^%^BOLD%^i%^CYAN%^c%^RESET%^%^BOLD%^l%^RESET%^e falls from the ceiling, causing a crash that carries throughout the tunnels.");
set_items(([
"ice" : "Whether the sheets, boulders of, or icicles - ice covers this entire area.",
"snow" : "The ground is covered in a thin layer of snow..",
"walls" : "The walls have an occasional torch, burning through blue ice to see blue rock.",
({"rock", "rocks"}) : "The rocks are all frozen, and have turned a bluish color.",
]));
set_exits(([ "northwest" : ROOMS "/icystuff/9.c",
"southwest" : ROOMS "/icystuff/12.c"]));
}

void reset() {
::reset();
if (!present("ogre")) {
new(MOBS+"ogremage2")->move(this_object());
}
}

