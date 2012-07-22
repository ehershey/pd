#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "no teleport" : 1, "night light" : 1]) );
set_smell("default", "The tunnel has a smokey, burning smell to it.");
set_listen("default", "The bubbling of lava can be heard throughout the tunnels.");
set_short("venturing through tunnels");
set_long("The molten tunnels steer in many directions, leading to nowhere in a %^RED%^%^BOLD%^heated %^RESET%^daze. Wisps of smoke float through the air, sometimes making shapes. The bubbling of %^RED%^l%^BOLD%^a%^YELLOW%^v%^RED%^a%^RESET%^ echoes off the walls. A %^BOLD%^%^BLACK%^black%^RESET%^ rock falls from the ceiling, causing a %^BOLD%^splash%^RESET%^ in the %^RED%^%^BOLD%^l%^RESET%^%^RED%^a%^YELLOW%^v%^BOLD%^a%^RESET%^ that carries throughout the tunnels. %^BOLD%^%^BLACK%^Bats %^RESET%^fly throughout the tunnels, screeching occasionally.");
set_items(([
"lava" : "There is a pool of lava on either side of you.",
"smoke" : "Wisps of smoke float through the air..",
"ground" : "The ground beneath you is a very hot looking rock path, surrounded by pools of lava..",
({"rock", "rocks"}) : "The path below you is made of rocks..",
]));
set_exits(([ "northwest" : ROOMS "/moltenlava/34.c",
"east" : ROOMS "/moltenlava/36.c"]));
}

void reset() {
::reset();
if (!present("ogre")) {
new(MOBS+"greenogre")->move(this_object());
}
}

