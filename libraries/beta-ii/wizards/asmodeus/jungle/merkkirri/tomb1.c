#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Entrance to the Merkkirri Catacombs");
set_long("You have been transported to a strange catacomb.  It is quite dark and cold.  Endless dust and cobwebs choke the walls and your only apparent exit is south down a dark tunnel.");
set_items(([
({"dust", "cobwebs"}): "The catacombs are full of dust and cobwebs.",
"tunnel" : "The tunnel is dark and cold.  Where it leads is anyone's guess.",
"walls" : "The walls are covered in dust yet you can make out the words '%^MAGENTA%^<%^RESET%^YELLOW%^chant%^MAGENTA%^>%^RESET%^ to return to the fountain' written on a one of the bricks.",
]));
set_properties((["light" : 1, "indoors" : 1,]));
set_exits(([
"south": MJUNGLE "tomb2.c",
"chant": MJUNGLE "msquare.c",
]));
add_invis_exit("chant");
set_smell("default", "The air is musty and stale.");
set_listen("default", "The echo of dripping water breaks the overwhelming silence.");
}

void reset() {
::reset();
if(!present("guardian"))
new(MOB "guardian.c")->move(this_object());
}
