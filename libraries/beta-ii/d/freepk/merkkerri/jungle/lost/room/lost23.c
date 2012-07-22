#include <lost.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
  ::create();
	set_short("The lost jungles of Merkkirri");
	set_long("The jungle looks to be thinning to the west, perhaps there is a clearing that way. The jungle floor is covered with many different types of footprints, many look to be from some sort of lizard, however they are far larger than any normal lizard could make. Hundreds of giant trees reach toward the sky, blocking out the sky. The leaves on the trees are far above the ground, well out of reach for even the largest of creatures.");
	set_property("forest",1);
	set_items(([
		"jungle" : "The jungle seems to have never been touched by evolution.  It's as if you are stepping millions of years into the past...",
		({"leaves", "trees", "plants"}): "The plantlife here is large and yet very simple in design.  It's as if the world evolved yet this place stood still.", 
		
	]));
	set_properties((["light" : 2, "night light" : 1,]));
	set_exits(([
		"northwest"	: ROOMS "lost24.c",
		"east"		: ROOMS "lost22.c",
	]));
}

void reset() {
 ::reset();
	if (!present("dinosaur", this_object()))
    	new(LOSTMOB"allosaurus.c")->move(this_object());
}
