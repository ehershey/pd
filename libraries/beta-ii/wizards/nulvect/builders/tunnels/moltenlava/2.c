#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "night light" : 1]) );
set_smell("default", "The tunnel has a smokey, burning smell to it.");
set_listen("default", "The bubbling of lava can be heard throughout the tunnels.");
set_short("venturing through tunnels");
set_long("The molten tunnels are %^RED%^%^BOLD%^flaming%^%^RESET%^ hot, and hard to see through with all the light. Stalagmite and stalactite make the tunnel look as if it is a mouth filled with fangs. Although there are no footprints on the ground, the walls seem to be chipped to let you know you aren't alone. %^RED%^%^BOLD%^Fl%^YELLOW%^a%^RESET%^%^RED%^m%^BOLD%^es%^RESET%^ randomly sprout from the ground, putting themselves out over time. Heat and smoke makes traveling the tunnels dangerous.");
set_items(([
"lava" : "There is a pool of lava on either side of you.",
"smoke" : "Wisps of smoke float through the air..",
"ground" : "The ground beneath you is a very hot looking rock path, surrounded by pools of lava..",
({"rock", "rocks"}) : "The path below you is made of rocks..",
]));
set_exits(([ "west" : ROOMS "/moltenlava/1.c",
"east" : ROOMS "/moltenlava/3.c"]));
}
