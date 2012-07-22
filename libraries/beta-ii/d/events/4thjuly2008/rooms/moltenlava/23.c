#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "no teleport" : 1, "night light" : 1]) );
set_smell("default", "The tunnel has a smokey, burning smell to it.");
set_listen("default", "The bubbling of lava can be heard throughout the tunnels.");
set_short("venturing through tunnels");
set_long("The molten tunnels ruthlessly %^YELLOW%^%^BOLD%^boil%^RESET%^ and %^RED%^%^BOLD%^burn%^RESET%^ beneath the rocky path. %^BOLD%^%^BLACK%^Bats %^RESET%^fly throughout the tunnels, screeching occasionally. Although there are no footprints on the ground, the walls seem to be chipped to let you know you aren't alone. Wisps of smoke float through the air, sometimes making shapes. The air is composed of a stiffling mixture of heat and sulfur.");
set_items(([
"lava" : "There is a pool of lava on either side of you.",
"smoke" : "Wisps of smoke float through the air..",
"ground" : "The ground beneath you is a very hot looking rock path, surrounded by pools of lava..",
({"rock", "rocks"}) : "The path below you is made of rocks..",
]));
set_exits(([ "west" : ROOMS "/moltenlava/22.c",
"northwest" : ROOMS "/moltenlava/24.c"]));
}

void reset() {
::reset();
if (!present("ogre")) {
new(MOBS+"ogremage")->move(this_object());
}
}

