#include <std.h>
#include <aziraphale.h>
inherit ROOM;
void create() {
   ::create();
     set_properties((["light": 1, "night light" : 0, "forest" : 1]));
     set_short("Kra'Toa'Kathor");
     set_long("Here the path has worked it's way north around a large stone monolith that has been erected to the south. The trees surrounding this place are ancient, and stretch hundreds of feet into the air.");
     set_exits(([
		"southwest"		: KEEPROOM"zforest/kratoan/entry.c",
		"southeast"		: KEEPROOM"zforest/kratoan/road1.c"
                ]));
     set_items(([
		"monolith"	: "The monolith stands south of here, blocking any direct route into the village, and forcing you to pass all the Kra'Toan sentries."
		]));

        if(!present("monster")) {
        new(KEEPMOB"zforest/kratoan/sentry.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/sentry.c")->move(this_object());
	}
}
