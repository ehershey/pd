
#include <lost.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("The lost jungles of Merkkirri");
set_day_long("Here the jungle has opened up slightly.  To the north you see the edge of a dark murky lake.  You also notice large footprints leading to the northeast.");
set_night_long("Here the jungle has opened up slightly.  To the north you see the edge of a dark murky lake.  You also notice large footprints leading to the northeast.");
set_property("forest",1);
set_items(([
"jungle" : "The jungle seems to have never been touched by evolution.  Its as if you are stepping millions of years into the past...",
({"leaves", "trees", "plants"}): "The plantlife here is large and yet very simple in design.  Its as if the world evolved yet this place stood still.",
"footprints" : "The footprints are huge and if you were to guess, you'd think they were created by a dragon or something equally as large.",
"lake" : "The lake is quite large and a little examination reveals that it is also extremely deep and very impassable.",
]));
set_properties((["light" : 2, "night light" : 1,]));
set_exits(([
"northeast": LOST "lost5.c",
"northwest": LOST "lost4.c",
"southeast": LOST "lost2.c",
]));
}

void reset() {
 ::reset();
}
