#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "night light" : 1]) );
set_smell("default", "The tunnel has a smokey, burning smell to it.");
set_listen("default", "The bubbling of lava can be heard throughout the tunnels.");
set_short("venturing through tunnels");
set_long("The molten tunnels ruthlessly %^YELLOW%^%^BOLD%^boil%^RESET%^ and %^RED%^%^BOLD%^burn%^RESET%^ beneath the rocky path. The air is composed of a stiffling mixture of heat and sulfur. %^BOLD%^%^WHITE%^Bones%^RESET%^ float throughout the %^RED%^l%^BOLD%^a%^ORANGE%^%^RESET%^v%^YELLOW%^a%^BOLD%^%^RESET%^... what sort of being would be so strong to have indestructible bones? %^BOLD%^%^BLACK%^Bats %^RESET%^fly throughout the tunnels, screeching occasionally. Heat and smoke makes traveling the tunnels dangerous.");
set_items(([
"lava" : "There is a pool of lava on either side of you.",
"smoke" : "Wisps of smoke float through the air..",
"ground" : "The ground beneath you is a very hot looking rock path, surrounded by pools of lava..",
({"rock", "rocks"}) : "The path below you is made of rocks..",
]));
set_exits(([ "west" : ROOMS "/moltenlava/7.c",
"northeast" : ROOMS "/moltenlava/9.c"]));
}
