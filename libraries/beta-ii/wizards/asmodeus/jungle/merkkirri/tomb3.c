#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Merkkirri Catacombs");
set_long("You are at the interection of two tunnels.  One leads to the north and the other runs east and west.  The catacomb is fearfully silent and every sound you make seems to be amplified.");
set_items(([
({"dust", "cobwebs"}): "The catacombs are full of dust and cobwebs.",
"tunnels" : "The tunnels are dark and cold.  Where they lead is anyone's guess.",
]));
set_properties((["light" : 1, "indoors" : 1,]));
set_exits(([
"north": MJUNGLE "tomb2.c",
"east": MJUNGLE "tomb4.c",
"west": MJUNGLE "tomb5.c",
]));
set_smell("default", "The air is musty and stale.");
set_listen("default", "The echo of dripping water breaks the overwhelming silence.");
new (MJUNGLE "symbol.c")->move(this_object());
}
