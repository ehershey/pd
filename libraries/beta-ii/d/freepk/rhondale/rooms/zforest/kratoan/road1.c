#include <std.h>
#include <aziraphale.h>
inherit ROOM;
void create() {
   ::create();
     set_properties((["light": 1, "night light" : 0, "forest" : 1]));
     set_short("Kra'Toa'Kathor");
     set_long("A stingy path through the forest leads off to the east, and splits off northwest and southwest to go around a large stone monolith. Here the forest blocks out so much light that it is perpetually dark.");
     set_exits(([
		"northwest"		: KEEPROOM"zforest/kratoan/pathne.c",
		"southwest"		: KEEPROOM"zforest/kratoan/pathse.c",
		"east"			: KEEPROOM"zforest/kratoan/road2.c"
                ]));
     set_items(([
		"monolith"	: "The monolith stands north of here, blocking any direct route into the village, and forcing you to pass all the Kra'Toan sentries."
		]));

        if(!present("monster")) {
        new(KEEPMOB"zforest/kratoan/sentry.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/sentry.c")->move(this_object());
	}
}
