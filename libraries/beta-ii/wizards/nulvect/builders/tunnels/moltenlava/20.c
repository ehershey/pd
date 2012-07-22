#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "night light" : 1]) );
set_smell("default", "The tunnel has a smokey, burning smell to it.");
set_listen("default", "The bubbling of lava can be heard throughout the tunnels.");
set_short("venturing through tunnels");
set_long("The molten tunnels ruthlessly %^YELLOW%^%^BOLD%^boil%^RESET%^ and %^RED%^%^BOLD%^burn%^RESET%^ beneath the rocky path. %^BOLD%^%^BLACK%^Bats %^RESET%^fly throughout the tunnels, screeching occasionally. Heat and smoke makes traveling the tunnels dangerous. The bubbling of %^RED%^l%^BOLD%^a%^YELLOW%^v%^RED%^a%^RESET%^ echoes off the walls. Shadows seem to creep through the smokey haze, although nothing can be seen for sure.");
set_items(([
"lava" : "There is a pool of lava on either side of you.",
"smoke" : "Wisps of smoke float through the air..",
"ground" : "The ground beneath you is a very hot looking rock path, surrounded by pools of lava..",
({"rock", "rocks"}) : "The path below you is made of rocks..",
]));
set_exits(([ "south" : ROOMS "/moltenlava/19.c",
"northeast" : ROOMS "/moltenlava/21.c"]));
}
