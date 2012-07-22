#include <lost.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
  ::create();
	set_short("The lost jungles of Merkkirri");
	set_long("The jungle remains difficult to navigate, huge vines hanging from the trees hang everywhere. To the North is a large lake, it looks to be rather murky. The giant trees tower into the sky, blocking out the sky.");
	set_property("forest",1);
	set_items(([
		"jungle" : "The jungle seems to have never been touched by evolution.  Its as if you are stepping millions of years into the past...",
		({"leaves", "trees", "plants"}): "The plantlife here is large and yet very simple in design.  Its as if the world evolved yet this place stood still.", 
		"lake" : "The lake is quite large and a little examination reveals that it is also extremely deep and very impassable.",
	]));
	set_properties((["light" : 2, "night light" : 1,]));
	set_exits(([
		"west"	   : ROOMS "lost3.c",
		"southeast": ROOMS "lost7.c",
	]));
}

void reset() {
 ::reset();
}
