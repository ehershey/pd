#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Crypt of the Fallen");
set_long("You are standing in a crypt where the ancient merkkirri buried their fallen warriors.  The Necromancers have brought many of these warriors back from the dead to serve the Merkkirri once again.");
set_items(([
({"dust", "cobwebs"}): "The catacombs are full of dust and cobwebs.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"west": MJUNGLE "tomb10.c",
]));
set_smell("default", "The air is musty and stale.");
set_listen("default", "The echo of dripping water breaks the overwhelming silence.");
}

void reset() {
::reset();
if(!present("warrior")) {
new(MOB "unmerk.c")->move(this_object());
new(MOB "unmerk.c")->move(this_object());
}
}
