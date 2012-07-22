#include <lost.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
  ::create();
	set_short("The lost jungles of Merkkirri");
	set_long("A small path through the jungle leads to the southeast from here. It looks like there are many small footprints on the ground, from what would seem to be a strange small creature. Strange shadows dance off in the distance of the jungle.");
	set_property("forest",1);
	set_items(([
		"jungle" : "The jungle seems to have never been touched by evolution.  Its as if you are stepping millions of years into the past...",
		({"leaves", "trees", "plants"}): "The plantlife here is large and yet very simple in design.  Its as if the world evolved yet this place stood still.", 
		"lake" : "The lake is quite large and a little examination reveals that it is also extremely deep and very impassable.",
	]));
	set_properties((["light" : 2, "night light" : 1,]));
	set_exits(([
		"northwest": ROOMS "lost6.c",
		"southeast": ROOMS "lost8.c",
	]));
}

void reset() {
 ::reset();
}
