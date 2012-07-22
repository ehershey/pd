#include <std.h>
#include <aziraphale.h>
inherit ROOM;
void create() {
   ::create();
     set_properties((["light": 1, "night light" : 0, "indoors" : 1]));
     set_short("Kra'Toa'Kathor");
     set_long("Inside the the great southern tree is a large room that has been intricately carved out of the tree itself. Every wall is covered with hundreds of runes, and both the floor and ceiling have a pattern of concentric circles. In the centre of the room lies a tree stump with a Dendrinar sitting atop it.");
     set_exits(([
		"out"			: KEEPROOM"zforest/kratoan/stree.c",
                ]));
     set_items(([
		]));

        if(!present("knowledge")) {
        new(KEEPMOB"zforest/kratoan/knowledge.c")->move(this_object());
	}
	if(!present("altarofknowledge")) {
        new(KEEPARMOUR"zforest/kratoan/knowledge.c")->move(this_object());
	}
}
