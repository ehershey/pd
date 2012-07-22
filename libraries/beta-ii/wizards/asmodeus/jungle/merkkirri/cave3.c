#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Inside a cave");
set_long("You travel along a small passageway formed by thousands of years of weathering.  The limestone walls of the cave glisten with moisture.");
set_listen("default", "The sound of water dripping echos throughout the cave.");
set_properties((["light" : 3, "indoors" : 3,]));
set_exits(([
"southwest": MJUNGLE "cave4.c",
"northeast" : MJUNGLE "cave1.c",
]));
set_items(([
"walls": "The limestone walls are smooth and damp.",
]));
}

void reset() {
 ::reset();

}
