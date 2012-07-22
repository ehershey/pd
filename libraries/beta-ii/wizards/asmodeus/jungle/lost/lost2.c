
#include <lost.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("The lost jungles of Merkkirri");
set_day_long("The slight trail continues to the northeast and back to the southwest.  Far off to the north a volcano spews ash and smoke high into the sky.  The humid jungle air clings to the plants and to all that inhabit the region.");
set_night_long("The slight trail continues to the northeast and back to the southwest.  Far off to the north a volcano spews ash and smoke high into the sky.  The humid jungle air clings to the plants and to all that inhabit the region.");
set_property("forest",1);
set_items(([
"jungle" : "The jungle seems to have never been touched by evolution.  Its as if you are stepping millions of years into the past...",
({"leaves", "trees", "plants"}): "The plantlife here is large and yet very simple in design.  Its as if the world evolved yet this place stood still.",
"volcano" : "The volcano has been a part of Merkkirri legend for many centuries.  While once frequented by the gnolls for its religious significance, all that has changed due to the Queen and her new 'god'.",
]));
set_properties((["light" : 2, "night light" : 1,]));
set_exits(([
"northeast": LOST "lost3.c",
"southwest": LOST "lost1.c",
]));
}

void reset() {
 ::reset();
}
