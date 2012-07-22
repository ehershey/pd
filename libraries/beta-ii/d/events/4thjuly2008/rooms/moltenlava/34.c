#include <std.h>
#include <id4.h>
#include <dragonevent.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "no teleport" : 1, "night light" : 1]) );
set_smell("default", "The tunnel has a smokey, burning smell to it.");
set_listen("default", "The bubbling of lava can be heard throughout the tunnels.");
set_short("venturing through tunnels");
set_long("The molten tunnels are %^RED%^%^BOLD%^flaming%^%^RESET%^ hot, and hard to see through with all the light. Stalagmite and stalactite make the tunnel look as if it is a mouth filled with fangs. %^BOLD%^%^WHITE%^Bones%^RESET%^ float throughout the %^RED%^l%^BOLD%^a%^ORANGE%^%^RESET%^v%^YELLOW%^a%^BOLD%^%^RESET%^... what sort of being would be so strong to have indestructible bones? All of the air seems to vibrate in the waves of heat. Although there are no footprints on the ground, the walls seem to be chipped to let you know you aren't alone.");
set_items(([
"lava" : "There is a pool of lava on either side of you.",
"smoke" : "Wisps of smoke float through the air..",
"ground" : "The ground beneath you is a very hot looking rock path, surrounded by pools of lava..",
({"rock", "rocks"}) : "The path below you is made of rocks..",
]));
set_exits(([ "northeast" : ROOMS "/moltenlava/32.c",
"southeast" : ROOMS "/moltenlava/35.c"]));
}

void reset() {
object ob;
::reset();
if (!present("ogre")) {
ob = new(MOBS+"ogremage");
ob->move(this_object());
if (!sizeof(children(DRAG_ITEMS+"redgem")))
  if(DRAG_D->query_data("canplacegems"))
  load_object(DRAG_ITEMS+"redgem")->move(ob);
}
}

