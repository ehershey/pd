#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "night light" : 1]) );
set_smell("default", "The tunnel has a fresh and frozen smell to it.");
set_listen("default", "Echos near and far can be heard throughout the chilly tunnels.");
set_short("venturing through icy tunnels");
set_long("The icy tunnels slip through many directions, sliding to nowhere. There is a strong sense of cleanliness here. Flakes of %^BOLD%^snow%^RESET%^ float through the air, sticking to any dry surfaces. The ground is covered in %^BOLD%^frozen%^RESET%^ stones of different sizes, scattered randomly throughout the %^BOLD%^snow%^RESET%^. There is a large torch hanging on the wall, burning through the %^BOLD%^%^CYAN%^ice%^RESET%^ and showing gravel.");
set_items(([
"ice" : "Whether the sheets, boulders of, or icicles - ice covers this entire area.",
"snow" : "The ground is covered in a thin layer of snow..",
"walls" : "The walls have an occasional torch, burning through blue ice to see blue rock.",
({"rock", "rocks"}) : "The rocks are all frozen, and have turned a bluish color.",
]));
set_exits(([ "northwest" : ROOMS "/icystuff/36.c",
"southeast" : ROOMS "/icystuff/6.c",
"northeast" : ROOMS "/icystuff/8.c"]));
}
