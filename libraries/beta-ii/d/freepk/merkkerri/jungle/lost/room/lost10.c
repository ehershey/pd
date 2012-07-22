#include <lost.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
  ::create();
	set_short("The lost jungles of Merkkirri");
	set_long("A large lake is here to the north, it looks to be very deep. This appears to be the only part of the lake that isn't completely overgrown with plants. Strange shapes can be seen far off in the distance in the middle of the lake. Ripples move across the water in strange patterns and directions, beasts must be swimming under the surface of the water.");
	set_property("forest",1);
	set_items(([
		"jungle" : "The jungle seems to have never been touched by evolution.  Its as if you are stepping millions of years into the past...",
		({"leaves", "trees", "plants"}): "The plantlife here is large and yet very simple in design.  Its as if the world evolved yet this place stood still.", 
		"lake" : "The lake is quite large and a little examination reveals that it is also extremely deep and very impassable.",
	]));
	set_properties((["light" : 2, "night light" : 1,]));
	set_exits(([
		"south"	   : ROOMS "lost4.c",
	]));
}

void reset() {
 ::reset();
}
