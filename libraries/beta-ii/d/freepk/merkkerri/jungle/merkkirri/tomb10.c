#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Merkkirri Catacombs");
set_long("You stand at the end of a tunnel that runs south.  The hall is lit by the same strange light.  You notice there are two rooms next to you, one to the east and one to the west.");
set_items(([
({"dust", "cobwebs"}): "The catacombs are full of dust and cobwebs.",
"tunnel" : "The tunnel is dark and cold.  Where it leads is anyone's guess.",
"light" : "The tunnel is lit lightly by a strange light.  You cant seem to find its source however.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"east": MJUNGLE "tomb16.c",
"west": MJUNGLE "tomb18.c",
"south": MJUNGLE "tomb8.c",
]));
set_smell("default", "The air is musty and stale.");
set_listen("default", "The echo of dripping water breaks the overwhelming silence.");
}
