#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "no teleport" : 1, "night light" : 1]) );
set_smell("default", "The tunnel has a fresh and frozen smell to it.");
set_listen("default", "Echos near and far can be heard throughout the chilly tunnels.");
set_short("venturing through icy tunnels");
set_long("You slip down the icy tunnel in a southern direction, given speed from coming down a boulder and being unable to stop for some time. As soon as you stop, you see an %^BOLD%^%^CYAN%^icy%^RESET%^ pile of bones shivers lazily between two frozen rocks. Slipperiness makes traveling the tunnels dangerous. The sound of dripping %^BOLD%^%^BLUE%^water%^RESET%^ echoes off the walls. Flakes of %^BOLD%^snow%^RESET%^ float through the air, sticking to any dry surfaces.");
set_items(([
"ice" : "Whether the sheets, boulders of, or icicles - ice covers this entire area.",
"snow" : "The ground is covered in a thin layer of snow..",
"walls" : "The walls have an occasional torch, burning through blue ice to see blue rock.",
({"rock", "rocks"}) : "The rocks are all frozen, and have turned a bluish color.",
]));
set_exits(([ "southeast" : ROOMS "/icystuff/11.c"]));
}

void reset() {
::reset();
if (!present("ogre")) {
new(MOBS+"ogremage2")->move(this_object());
}
}

