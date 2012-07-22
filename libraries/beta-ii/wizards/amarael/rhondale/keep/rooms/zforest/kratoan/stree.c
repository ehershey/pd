#include <std.h>
#include <aziraphale.h>
inherit ROOM;
void create() {
   ::create();
     set_properties((["light": 1, "night light" : 0, "forest" : 1]));
     set_short("Kra'Toa'Kathor");
     set_day_long("The great southern tree stretches up high into the sky, and at the very top the branches that allow you to climb up create a level platfrom all around the tree. A doorway here allows you to enter.");
     set_night_long("The great southern tree stretches up high into the night sky, and at the very top the branches that allow you to climb up create a level platfrom all around the tree. A doorway here allows you to enter.");
     set_exits(([
		"enter"			: KEEPROOM"zforest/kratoan/knowledge.c",
		"down"			: KEEPROOM"zforest/kratoan/scamp.c"
                ]));
     set_items(([
		]));

        if(!present("monster")) {
        new(KEEPMOB"zforest/kratoan/denguard.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/denguard.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/denguard.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/sentry.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/sentry.c")->move(this_object());
	}
}
