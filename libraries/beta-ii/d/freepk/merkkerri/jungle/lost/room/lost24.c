#include <lost.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
  ::create();
	set_short("The lost jungles of Merkkirri");
	set_long("A clearing in the jungle can be seen to the west, however the jungle is far too dense to reach. A path leads to the north, it looks to be travelled by many different types of large beasts. The path is lined with large leafed plants, many look to have been recently eaten by something. Many of the trees in the area are covered with moss, hiding the trees true color.");
	set_property("forest",1);
	set_items(([
		"jungle" : "The jungle seems to have never been touched by evolution.  It's as if you are stepping millions of years into the past...",
		({"leaves", "trees", "plants"}): "The plantlife here is large and yet very simple in design.  It's as if the world evolved yet this place stood still.", 
		
	]));
	set_properties((["light" : 2, "night light" : 1,]));
	set_exits(([
		"southeast"	: ROOMS "lost23.c",
		"north"		: ROOMS "lost25.c",
                "southwest"      : ROOMS "lost_field001.c", 
	]));
}

void reset() {
 ::reset();
}
