#include <lost.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
  ::create();
	set_short("The lost jungles of Merkkirri");
	set_long("A small path through the jungle leads to the southeast and northwest from here. The jungle springs up from everywhere, giant trees fill the sky, Large vines hang from the giant trees, making it impossible to see very far. To the southeast, what looks to be a small puff of smoke flows into the air.");
	set_property("forest",1);
	set_items(([
		"jungle" : "The jungle seems to have never been touched by evolution.  Its as if you are stepping millions of years into the past...",
		({"leaves", "trees", "plants"}): "The plantlife here is large and yet very simple in design.  Its as if the world evolved yet this place stood still.", 

	]));
	set_properties((["light" : 2, "night light" : 1,]));
	set_exits(([
		"northwest": ROOMS "lost7.c",
		"southeast": ROOMS "lost9.c",
	]));
}

void reset() {
 ::reset();
	if (!present("dinosaur", this_object()))
    	new(LOSTMOB"dromaeosaurus.c")->move(this_object());
}
