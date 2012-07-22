#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Inside a cave");
set_long("You have entered what appears to be a hideout for several gnolls.  These ones however wear different armor from the other Merkkirri.  As you glance around you see tables with maps and other documents scattered across.  A small passageway leads to the southwest.");
set_properties((["light" : 3, "indoors" : 3,]));
set_exits(([
"out": MJUNGLE "mjungle40.c",
"north" : MJUNGLE "cave2.c",
"southwest": MJUNGLE "cave3.c",
]));
set_items(([
"maps": "The maps seems to be of the nearby area as well as of a large city located somewhere to the far southwest.  Perhaps they were drawing battle plans?",
"documents" : "The documents are all written in Merkish however they seem to have been encrypted.",
"tables" : "The tables are made of wood and are nothing special.",
]));
}

void reset() {
 ::reset();

if(!present("renegade")) {
new(MOB "btrenegade.c")->move(this_object());
new(MOB "btrenegade2.c")->move(this_object());
}
}
