#include <std.h>
#include <aziraphale.h>
inherit ROOM;
void create() {
   ::create();
     set_properties((["light": 1, "night light" : 0, "forest" : 1]));
     set_short("Kra'Toa'Kathor");
     set_day_long("Kra'Toa'Kathor is a most beautiful place where the evil of the world holds no sway. The sun shines through the leaves high overhead, creating beams of golden light. The open forest splits into three paths going northeast, east and southeast.");
     set_night_long("Kra'Toa'Kathor is a most beautiful place where the evil of the world holds no sway. The moons shine through the leaves high overhead, creating beams of silver light. The open forest splits into three paths going northeast, east and southeast.");
     set_exits(([
		"west"			: KEEPROOM"zforest/kratoan/road2.c",
		"east"			: KEEPROOM"zforest/kratoan/road4.c",
		"northeast"		: KEEPROOM"zforest/kratoan/ncamp.c",
		"southeast"		: KEEPROOM"zforest/kratoan/scamp.c"
                ]));
     set_items(([
		]));

        if(!present("monster")) {
        new(KEEPMOB"zforest/kratoan/sentry.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/villager.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/villager.c")->move(this_object());
	}
}
