#include <lost.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
  ::create();
	set_short("The lost jungles of Merkkirri");
	set_long("Large trees can be seen in all directions, they make is impossible to see far in any direction. Each tree has dozens of large vines hanging from them, all swaying differently in the wind. The vines shadows make it look like there are large creatures moving off in the distance. The ground is hard and dry, the trees must soak up most of the water before it reaches the ground.");
	set_property("forest",1);
	set_items(([
		"jungle" : "The jungle seems to have never been touched by evolution.  It's as if you are stepping millions of years into the past...",
		({"leaves", "trees", "plants"}): "The plantlife here is large and yet very simple in design.  It's as if the world evolved yet this place stood still.", 
		
	]));
	set_properties((["light" : 2, "night light" : 1,]));
	set_exits(([
		"east"			: ROOMS "lost38.c",
		"west"	   		: ROOMS "lost36.c",
	]));
}

void reset() {
 ::reset();
	if (!present("dinosaur", this_object()))
    	new(LOSTMOB"ankylosaurus.c")->move(this_object());
	if (!present("dinosaur 2", this_object()))
    	new(LOSTMOB"ankylosaurus.c")->move(this_object());
}
