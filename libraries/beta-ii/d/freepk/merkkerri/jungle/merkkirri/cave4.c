
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Inside a cave");
set_long("The passageway narrows here making it difficult to squeeze through.  You see torchlight coming from the southwestern direction which is causing the walls to glisten.");
set_listen("default", "The sound of watter dripping echos throughout the cave.");
set_properties((["light" : 0, "indoors" : 0,]));
set_exits(([
"northeast" : MJUNGLE "cave3.c",
]));
set_items(([
"walls": "The limestone walls are smooth and damp.",
]));
}

void reset() {
 ::reset();

}
