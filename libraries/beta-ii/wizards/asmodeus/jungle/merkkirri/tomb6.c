#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Merkkirri Catacombs");
set_long("The tunnel turns to the north here.  The hall is lit by a strange light here but its source remains to be seen.  The whole area crawls with evil.");
set_items(([
({"dust", "cobwebs"}): "The catacombs are full of dust and cobwebs.",
"tunnel" : "The tunnel is dark and cold.  Where it leads is anyone's guess.",
"light" : "The tunnel is lit lightly by a strange light.  You cant seem to find its source however.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"west": MJUNGLE "tomb4.c",
"north": MJUNGLE "tomb8.c",
]));
set_smell("default", "The air is musty and stale.");
set_listen("default", "The echo of dripping water breaks the overwhelming silence.");
}
