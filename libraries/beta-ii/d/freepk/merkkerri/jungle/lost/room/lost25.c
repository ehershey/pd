#include <lost.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
  ::create();
	set_short("The lost jungles of Merkkirri");
	set_long("Huge vines hang from the trees, each one covered with sharp thorns. The vines sway in the wind, making their shadows dance on the trees. A path goes from the northeast to the south, it looks to have been made by animals walking from the clearing to the west. The path is littered with footprints from all sorts of strange beasts, every print looks to come from something large and dangerous.");
	set_property("forest",1);
	set_items(([
		"jungle" : "The jungle seems to have never been touched by evolution.  It's as if you are stepping millions of years into the past...",
		({"leaves", "trees", "plants"}): "The plantlife here is large and yet very simple in design.  It's as if the world evolved yet this place stood still.", 
		
	]));
	set_properties((["light" : 2, "night light" : 1,]));
	set_exits(([
		"northeast"	: ROOMS "lost26.c",
		"south"		: ROOMS "lost24.c",
	]));
}

void reset() {
 ::reset();
}
