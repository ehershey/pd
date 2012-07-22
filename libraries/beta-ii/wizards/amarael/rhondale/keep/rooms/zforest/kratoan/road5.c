#include <std.h>
#include <aziraphale.h>
inherit ROOM;
void create() {
   ::create();
     set_properties((["light": 1, "night light" : 0, "forest" : 1]));
     set_short("Kra'Toa'Kathor");
     set_day_long("The clearing here splits up with three paths going northwest, west and southwest all joining the main pathway that leads to a large temple further to the east. It is very beautiful here, with golden beams of sunlight dancing in the air.");
     set_night_long("The clearing here splits up with three paths going northwest, west and southwest all joining the main pathway that leads to a large temple further to the east. It is very beautiful here, with silver beams of moonlight dancing in the air.");
     set_exits(([
		"west"			: KEEPROOM"zforest/kratoan/road4.c",
		"east"			: KEEPROOM"zforest/kratoan/road6.c",
		"northwest"		: KEEPROOM"zforest/kratoan/ncamp.c",
		"southwest"		: KEEPROOM"zforest/kratoan/scamp.c",

                ]));
     set_items(([
		]));

        if(!present("monster")) {
        new(KEEPMOB"zforest/kratoan/villager.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/villager.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/villager.c")->move(this_object());
	}
}
