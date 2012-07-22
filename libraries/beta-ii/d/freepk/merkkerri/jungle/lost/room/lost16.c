#include <lost.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
  ::create();
	set_short("The lost jungles of Merkkirri");
	set_long("There are very few smaller plants in this part of the jungle, the area is mostly filled with large trees. The ground is covered with dead tree leaves, each leaf is gigantic in size. Strange crunching sounds come from all directions, it sounds like some beast is stepping on the dead leaves off in the distance.");
	set_property("forest",1);
	set_items(([
		"jungle" : "The jungle seems to have never been touched by evolution.  It's as if you are stepping millions of years into the past...",
		({"leaves", "trees", "plants"}): "The plantlife here is large and yet very simple in design.  It's as if the world evolved yet this place stood still.", 
		
	]));
	set_properties((["light" : 2, "night light" : 1,]));
	set_exits(([
		"northeast"		: ROOMS "lost17.c",
		"southwest"		: ROOMS "lost15.c",
		"northwest"		: ROOMS "lost30.c",
	]));
}

void reset() {
 ::reset();
}
