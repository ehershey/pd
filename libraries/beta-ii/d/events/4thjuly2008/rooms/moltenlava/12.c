#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "no teleport" : 1, "night light" : 1]) );
set_smell("default", "The tunnel has a smokey, burning smell to it.");
set_listen("default", "The bubbling of lava can be heard throughout the tunnels.");
set_short("venturing through tunnels");
set_long("The molten tunnels are %^RED%^%^BOLD%^flaming%^%^RESET%^ hot, and hard to see through with all the light. The bubbling of %^RED%^l%^BOLD%^a%^YELLOW%^v%^RED%^a%^RESET%^ echoes off the walls. All of the air seems to vibrate in the waves of heat. %^BOLD%^%^BLACK%^Bats %^RESET%^fly throughout the tunnels, screeching occasionally. %^BOLD%^%^BLACK%^Bats %^RESET%^fly throughout the tunnels, screeching occasionally.");
set_items(([
"lava" : "There is a pool of lava on either side of you.",
"smoke" : "Wisps of smoke float through the air..",
"ground" : "The ground beneath you is a very hot looking rock path, surrounded by pools of lava..",
({"rock", "rocks"}) : "The path below you is made of rocks..",
]));
set_exits(([ "northeast" : ROOMS "/moltenlava/11.c"]));
}

void reset() {
::reset();
if (!present("ogre")) {
new(MOBS+"ogremage")->move(this_object());
}
}

