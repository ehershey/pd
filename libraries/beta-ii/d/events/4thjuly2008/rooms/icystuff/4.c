#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "no teleport" : 1, "night light" : 1]) );
set_smell("default", "The tunnel has a fresh and frozen smell to it.");
set_listen("default", "Echos near and far can be heard throughout the chilly tunnels.");
set_short("venturing through icy tunnels");
set_long("The icy tunnels are completely covered in a bright blue sheet of ice. An %^BOLD%^%^CYAN%^icy%^RESET%^ pile of bones shivers lazily between two frozen rocks. Slipperiness makes traveling the tunnels dangerous. A blinding light reflects off of every icy surface. Flakes of %^BOLD%^snow%^RESET%^ float through the air, sticking to any dry surfaces.");
set_items(([
"ice" : "Whether the sheets, boulders of, or icicles - ice covers this entire area.",
"snow" : "The ground is covered in a thin layer of snow..",
"walls" : "The walls have an occasional torch, burning through blue ice to see blue rock.",
({"rock", "rocks"}) : "The rocks are all frozen, and have turned a bluish color.",
]));
set_exits(([ "west" : ROOMS "/icystuff/3.c",
"northeast" : ROOMS "/icystuff/5.c"]));
}

void reset() {
::reset();
if (!present("ogre 2")) {
new(MOBS+"ogrethug")->move(this_object());
new(MOBS+"ogrethug")->move(this_object());
}
}

