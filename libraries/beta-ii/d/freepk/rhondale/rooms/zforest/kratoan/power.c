#include <std.h>
#include <aziraphale.h>
inherit ROOM;
void create() {
   ::create();
     set_properties((["light": 1, "night light" : 0, "indoors" : 1]));
     set_short("Kra'Toa'Kathor");
     set_long("Inside the the great northern tree is a large room that has been intricately carved out of the tree itself. Every wall is covered with hundreds of runes, and both the floor and ceiling have a spiderweb pattern. In the centre of the room lies a tree stump with a Dendrinar standing atop it.");
     set_exits(([
		"out"			: KEEPROOM"zforest/kratoan/ntree.c",
                ]));
     set_items(([
		]));

        new(KEEPMOB"zforest/kratoan/power.c")->move(this_object());
        new(KEEPARMOUR"zforest/kratoan/knowledge.c")->move(this_object());
}
