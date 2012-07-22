#include <lost.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
  ::create();
	set_short("The lost jungles of Merkkirri");
	set_long("Huge flowers dot the jungle floor, each flower is almost as large as the trees are round. They almost seem to pour pollen into the air. The jungle floor around the flowers is covered with dead leaves from the trees, each leaf is as large as one of the flowers. Countless vines hang from the trees, making it look like some large creatures are moving off in the distance.");
	set_property("forest",1);
	set_items(([
		"jungle" : "The jungle seems to have never been touched by evolution.  It's as if you are stepping millions of years into the past...",
		({"leaves", "trees", "plants"}): "The plantlife here is large and yet very simple in design.  It's as if the world evolved yet this place stood still.", 
		
	]));
	set_properties((["light" : 2, "night light" : 1,]));
	set_exits(([
		"southeast"		: ROOMS "lost13.c",
		"west"	   		: ROOMS "lost22.c",
		"north"			: ROOMS "lost15.c",
	]));
}

void reset() {
 ::reset();
}
