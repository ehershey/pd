#include <std.h>
#include <aziraphale.h>
inherit ROOM;
void create() {
   ::create();
     set_properties((["light": 1, "night light" : 0, "forest" : 1]));
     set_short("Kra'Toa'Kathor");
     set_day_long("The clearing in the southern part of the village is bare except for a huge tree that must be thousands of years old. It's trunk is more than forty feet thick. Branches all around it provide an easy way to climb up and down, with many people doing just that");
     set_night_long("The clearing in the southern part of the village is bare except for a huge tree that must be thousands of years old. It's trunk is more than forty feet thick, and branches all around it provide an easy way to climb up.");
     set_exits(([
		"northwest"		: KEEPROOM"zforest/kratoan/road3.c",
		"northeast"		: KEEPROOM"zforest/kratoan/road5.c",
		"up"			: KEEPROOM"zforest/kratoan/stree.c"
                ]));
     set_items(([
		]));

        if(!present("monster")) {
        new(KEEPMOB"zforest/kratoan/villager.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/villager.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/sentry.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/sentry.c")->move(this_object());
	}
}
