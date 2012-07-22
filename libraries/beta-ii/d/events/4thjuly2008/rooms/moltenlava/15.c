#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "no teleport" : 1, "night light" : 1]) );
set_smell("default", "The tunnel has a smokey, burning smell to it.");
set_listen("default", "The bubbling of lava can be heard throughout the tunnels.");
set_short("venturing through tunnels");
set_long("The molten tunnels are %^RED%^%^BOLD%^flaming%^%^RESET%^ hot, and hard to see through with all the light. %^BOLD%^%^WHITE%^Bones%^RESET%^ float throughout the %^RED%^l%^BOLD%^a%^ORANGE%^%^RESET%^v%^YELLOW%^a%^BOLD%^%^RESET%^... what sort of being would be so strong to have indestructible bones? %^BOLD%^%^BLACK%^Bats %^RESET%^fly throughout the tunnels, screeching occasionally. Although there are no footprints on the ground, the walls seem to be chipped to let you know you aren't alone. Heat and smoke makes traveling the tunnels dangerous.");
set_items(([
"lava" : "There is a pool of lava on either side of you.",
"smoke" : "Wisps of smoke float through the air..",
"ground" : "The ground beneath you is a very hot looking rock path, surrounded by pools of lava..",
({"rock", "rocks"}) : "The path below you is made of rocks..",
]));
set_exits(([ "northeast" : ROOMS "/moltenlava/13.c",
"southeast" : ROOMS "/moltenlava/16.c"]));
}

void reset() {
::reset();
if (!present("ogre 3")) {
new(MOBS+"bigogre")->move(this_object());
new(MOBS+"ogremonk")->move(this_object());
new(MOBS+"ogrethug")->move(this_object());
}
}

