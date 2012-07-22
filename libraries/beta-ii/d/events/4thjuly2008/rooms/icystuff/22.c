#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "no teleport" : 1, "night light" : 1]) );
set_smell("default", "The tunnel has a fresh and frozen smell to it.");
set_listen("default", "Echos near and far can be heard throughout the chilly tunnels.");
set_short("venturing through icy tunnels");
set_long("The icy tunnels hopelessly slip and slide in many directions. A blinding light reflects off of every icy surface. A large %^BOLD%^i%^RESET%^%^BLUE%^c%^RESET%^%^BOLD%^i%^CYAN%^c%^RESET%^%^BOLD%^l%^RESET%^e falls from the ceiling, causing a crash that carries throughout the tunnels. There is a strong sense of cleanliness here. Footprints can be seen in the %^BOLD%^snow%^RESET%^, heading in all directions.");
set_items(([
"ice" : "Whether the sheets, boulders of, or icicles - ice covers this entire area.",
"snow" : "The ground is covered in a thin layer of snow..",
"walls" : "The walls have an occasional torch, burning through blue ice to see blue rock.",
({"rock", "rocks"}) : "The rocks are all frozen, and have turned a bluish color.",
]));
set_exits(([ "northwest" : ROOMS "/icystuff/20.c",
"southeast" : ROOMS "/icystuff/24.c"]));
}

void reset() {
::reset();
if (!present("ogre 3")) {
new(MOBS+"ogre")->move(this_object());
new(MOBS+"ogremonk")->move(this_object());
new(MOBS+"ogre")->move(this_object());
}
}

