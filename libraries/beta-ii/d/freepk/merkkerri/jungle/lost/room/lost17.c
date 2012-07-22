#include <lost.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
  ::create();
	set_short("The lost jungles of Merkkirri");
	set_long("The jungle is very thick, large trees can be seen in all directions. Huge vines hang from the trees, swaying in the wind. The ground is covered in strange tracks and dead plants, something very big have been moving around in the jungle. Moss grows everywhere, covering most of the trees.");
	set_property("forest",1);
	set_items(([
		"jungle" : "The jungle seems to have never been touched by evolution.  It's as if you are stepping millions of years into the past...",
		({"leaves", "trees", "plants"}): "The plantlife here is large and yet very simple in design.  It's as if the world evolved yet this place stood still.", 
		
	]));
	set_properties((["light" : 2, "night light" : 1,]));
	set_exits(([
		"north"			: ROOMS "lost18.c",
		"southwest"	   	: ROOMS "lost16.c",
	]));
}

void reset() {
 ::reset();
	if (!present("dinosaur", this_object()))
    	new(LOSTMOB"allosaurus.c")->move(this_object());
}
