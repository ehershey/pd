#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Beneath the tree");
set_long("You have entered what appears to be a den of some panthers.  The lighting is terrible yet it is clear just by the sounds of the panthers make that you are not wanted here.  The only way out is the way you came.");
set_property("forest",1);
set_properties((["light" : 0, "indoors" : 0,]));
set_exits(([
"out" : MJUNGLE "mjungle4.c",
]));
}

void reset() {
::reset();
if(!present("black panther")) {
new(MOB "panther")->move(this_object());
new(MOB "panther")->move(this_object());
new(MOB "panther")->move(this_object());
}
}
