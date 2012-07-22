#include <lost.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
  ::create();
	set_short("The lost jungles of Merkkirri");
	set_long("Large brown trees make it impossible to see very far in any direction. The trees almost block out the sky with their size, only small patches of the sky above can be seen. Large vines hang from the trees, making strange noises as they sway.");
	set_property("forest",1);
	set_items(([
		"jungle" : "The jungle seems to have never been touched by evolution.  It's as if you are stepping millions of years into the past...",
		({"leaves", "trees", "plants"}): "The plantlife here is large and yet very simple in design.  It's as if the world evolved yet this place stood still.", 
		
	]));
	set_properties((["light" : 2, "night light" : 1,]));
	set_exits(([
		"west"			: ROOMS "lost34.c",
		"northeast"	   	: ROOMS "lost36.c",
	]));
}

void reset() {
 ::reset();

}
