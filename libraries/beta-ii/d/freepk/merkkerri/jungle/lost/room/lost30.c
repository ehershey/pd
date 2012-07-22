#include <lost.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
  ::create();
	set_short("The lost jungles of Merkkirri");
	set_long("The jungle is thick with plant life, it is impossible to see very far in any direction. Large archaic plants line the jungle floor, the leaves on each plant look strange and large. Large vines hang from the trees, each vine has large sharp thorns growing from it.");
	set_property("forest",1);
	set_items(([
		"jungle" : "The jungle seems to have never been touched by evolution.  It's as if you are stepping millions of years into the past...",
		({"leaves", "trees", "plants"}): "The plantlife here is large and yet very simple in design.  It's as if the world evolved yet this place stood still.", 
		
	]));
	set_properties((["light" : 2, "night light" : 1,]));
	set_exits(([
		"southeast"	: ROOMS "lost16.c",
		"north"		: ROOMS "lost29.c",
	]));
}

void reset() {
 ::reset();
}
