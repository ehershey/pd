#include <lost.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
  ::create();
	set_short("The lost jungles of Merkkirri");
	set_long("The ground is covered with large leafed plants, they make the ground beneath them impossible to see. Anywhere the plants do not grow, a large tree springs from the ground toward to sky. Each tree has countless vines hanging from them, each one seems to sway differently in the wind. The leaves on the trees are high in the air, far out of reach for even the largest of dragon.");
	set_property("forest",1);
	set_items(([
		"jungle" : "The jungle seems to have never been touched by evolution.  It's as if you are stepping millions of years into the past...",
		({"leaves", "trees", "plants"}): "The plantlife here is large and yet very simple in design.  It's as if the world evolved yet this place stood still.", 
		
	]));
	set_properties((["light" : 2, "night light" : 1,]));
	set_exits(([
		"east"			: ROOMS "lost37.c",
		"north"	   		: ROOMS "lost47.c",
		"southwest"		: ROOMS "lost35.c",
	]));
}

void reset() {
 ::reset();
}
