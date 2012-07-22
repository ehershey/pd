#include <lost.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
  ::create();
	set_short("The lost jungles of Merkkirri");
	set_long("Hundreds of vines hang from the trees, each one sways differently in the wind. Large shadows dance off in the distance, making it look like there is some large creature off in the distance. Gigantic trees reach into the sky from the jungle floor, they block out the sky. The leaves on the trees seem to be unusually large.");
	set_property("forest",1);
	set_items(([
		"jungle" : "The jungle seems to have never been touched by evolution.  It's as if you are stepping millions of years into the past...",
		({"leaves", "trees", "plants"}): "The plantlife here is large and yet very simple in design.  It's as if the world evolved yet this place stood still.", 
		
	]));
	set_properties((["light" : 2, "night light" : 1,]));
	set_exits(([
		"south"			: ROOMS "lost20.c",
	]));
}

void reset() {
 ::reset();
	if (!present("dinosaur", this_object()))
    	new(LOSTMOB"allosaurus.c")->move(this_object());
}
