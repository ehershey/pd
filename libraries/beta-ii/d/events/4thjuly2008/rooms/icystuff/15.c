#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "no teleport" : 1, "night light" : 1]) );
set_smell("default", "The tunnel has a fresh and frozen smell to it.");
set_listen("default", "Echos near and far can be heard throughout the chilly tunnels.");
set_short("venturing through icy tunnels");
set_long("The icy tunnels hopelessly slip and slide in many directions. A large %^BOLD%^i%^RESET%^%^BLUE%^c%^RESET%^%^BOLD%^i%^CYAN%^c%^RESET%^%^BOLD%^l%^RESET%^e falls from the ceiling, causing a crash that carries throughout the tunnels. An %^BOLD%^%^CYAN%^icy%^RESET%^ pile of bones shivers lazily between two frozen rocks. There is a strong sense of cleanliness here. The ground is covered in %^BOLD%^frozen%^RESET%^ stones of different sizes, scattered randomly throughout the %^BOLD%^snow%^RESET%^.");
set_items(([
"ice" : "Whether the sheets, boulders of, or icicles - ice covers this entire area.",
"snow" : "The ground is covered in a thin layer of snow..",
"walls" : "The walls have an occasional torch, burning through blue ice to see blue rock.",
({"rock", "rocks"}) : "The rocks are all frozen, and have turned a bluish color.",
]));
set_exits(([ "northwest" : ROOMS "/icystuff/14.c",
"east" : ROOMS "/red_entrance",
"southwest" : ROOMS "/icystuff/16.c"]));
}

void reset() {
::reset();
if (!present("ogre 4")) {
new(MOBS+"ogre")->move(this_object());
new(MOBS+"ogre")->move(this_object());
new(MOBS+"ogrethug")->move(this_object());
new(MOBS+"ogre")->move(this_object());
}
}

