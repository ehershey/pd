#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Inside Burham Woods");
set_day_long("A group of tents is set up but no one is around. The campfire is smothered with dirt and thick black smoke rises to above the forest. ");
set_night_long("You are warmed by the bonfire in the middle of the tents. You feel comfortable next to the fire but you do not feel safe. There is a light coming from one of the tents.");
set_items(([
"sunlight" : "Just barely any.",
"canopy" : "The trees grow quite tall.",
"tents" : "Set up by Soldiers.",
"fire": "Warm and soothing.",
"trees": "Don't kid yourself.. trees? in a forest?"
]));

set_smell("default","The ocean and nature mix into a sweet scent.");
set_listen("default","The sounds of swords clashing echoes throughout.");
set_exits( ([ "south": "/wizards/powerman/room/forestwestb3.c",
              "north": "/wizards/powerman/room/forestwesta1.c",
              "west" : "/wizards/powerman/room/forestwesta2.c",
              "tent" : "/wizards/powerman/room/tent1.c",
              "east" : "/wizards/powerman/room/forestmida2.c" ]));
}

void reset()
{
 ::reset();
if(query_night() && !present("soldier"))
{
}
else
if(!present("soldier")) {
new("/wizards/powerman/arm/forsold")->move(this_object());
new("/wizards/powerman/arm/forsold")->move(this_object());
new("/wizards/powerman/arm/forsold")->move(this_object());
}
}

