#include <lost.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
  ::create();
	set_short("The lost jungles of Merkkirri");
	set_long("The jungle remains difficult to navigate, huge vines hanging from the trees hang everywhere. To the North is a large lake, it looks to be rather murky. The giant trees tower into the sky, blocking out the sky. It looks like some creature has been grazing here recently, many of the plants have been torn up and have teethe marks on them.");
	set_property("forest",1);
	set_items(([
		"jungle" : "The jungle seems to have never been touched by evolution.  It's as if you are stepping millions of years into the past...",
		({"leaves", "trees", "plants"}): "The plantlife here is large and yet very simple in design.  It's as if the world evolved yet this place stood still.", 
		
	]));
	set_properties((["light" : 2, "night light" : 1,]));
	set_exits(([
		"southeast": ROOMS "lost3.c",
		"northwest": ROOMS "lost11.c",
	]));
}

void reset() {
 ::reset();
	if (!present("dinosaur", this_object()))
    	new(LOSTMOB"dromaeosaurus.c")->move(this_object());
}

