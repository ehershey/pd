#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "no teleport" : 1, "night light" : 1]) );
set_smell("default", "The tunnel has a smokey, burning smell to it.");
set_listen("default", "The bubbling of lava can be heard throughout the tunnels.");
set_short("venturing through tunnels");
set_long("The molten tunnels are %^RED%^%^BOLD%^flaming%^%^RESET%^ hot, and hard to see through with all the light. %^RED%^%^BOLD%^Fl%^YELLOW%^a%^RESET%^%^RED%^m%^BOLD%^es%^RESET%^ randomly sprout from the ground, putting themselves out over time. %^BOLD%^%^WHITE%^Bones%^RESET%^ float throughout the %^RED%^l%^BOLD%^a%^ORANGE%^%^RESET%^v%^YELLOW%^a%^BOLD%^%^RESET%^... what sort of being would be so strong to have indestructible bones? All of the air seems to vibrate in the waves of heat. The bubbling of %^RED%^l%^BOLD%^a%^YELLOW%^v%^RED%^a%^RESET%^ echoes off the walls.");
set_items(([
"lava" : "There is a pool of lava on either side of you.",
"smoke" : "Wisps of smoke float through the air..",
"ground" : "The ground beneath you is a very hot looking rock path, surrounded by pools of lava..",
({"rock", "rocks"}) : "The path below you is made of rocks..",
]));
set_exits(([ "northeast" : ROOMS "/moltenlava/26.c",
"east" : ROOMS "/moltenlava/24.c"]));
}

void reset() {
::reset();
if (!present("ogre")) {
new(MOBS+"ogremage")->move(this_object());
}
}

