#include <lost.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
  ::create();
	set_short("The lost jungles of Merkkirri");
	set_long("The jungle is dense and hot, countless plants line the forest floor. Each plant is covered with large green leaves, each one with its own distinct pattern and shape. Wherever there are no plants, trees tower into the sky. Each tree is enormous in size, by far the biggest trees in all the lands.");
	set_property("forest",1);
	set_items(([
		"jungle" : "The jungle seems to have never been touched by evolution.  It's as if you are stepping millions of years into the past...",
		({"leaves", "trees", "plants"}): "The plantlife here is large and yet very simple in design.  It's as if the world evolved yet this place stood still.", 
		
	]));
	set_properties((["light" : 2, "night light" : 1,]));
	set_exits(([
		"north"			: ROOMS "lost32.c",
		"south"			: ROOMS "lost28.c",
		"northeast"		: ROOMS "lost33.c",
	]));
}

void reset() {
 ::reset();
}
