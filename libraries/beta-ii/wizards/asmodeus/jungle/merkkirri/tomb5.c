#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Merkkirri Catacombs");
set_long("You are in a long tunnel that runs east and west.  Darkness surrounds you and the cool air gives you an eerie chill.");
set_items(([
({"dust", "cobwebs"}): "The catacombs are full of dust and cobwebs.",
"tunnel" : "The tunnel is dark and cold.  Where it leads is anyone's guess.",
]));
set_properties((["light" : 1, "indoors" : 1,]));
set_exits(([
"east": MJUNGLE "tomb3.c",
"west": MJUNGLE "tomb7.c",
]));
set_smell("default", "The air is musty and stale.");
set_listen("default", "The echo of dripping water breaks the overwhelming silence.");
}
