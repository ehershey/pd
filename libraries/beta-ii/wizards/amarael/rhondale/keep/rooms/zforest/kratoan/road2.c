#include <std.h>
#include <aziraphale.h>
inherit ROOM;
void create() {
   ::create();
     set_properties((["light": 1, "night light" : 0, "forest" : 1]));
     set_short("Kra'Toa'Kathor");
     set_day_long("The forest opens up completely and shows a most spectacular view. Sunlight streams down between the leaves above, creating thousands of golden beams shimmering through the air. A huge archway of wood stretches over the entire place marking the true entrance into what must surely be a sacred place.");
     set_night_long("The forest opens up completely and shows a most spectacular view. Moonlight streams down between the leaves above, creating thousands of silver beams shimmering through the air. A huge archway of wood stretches over the entire place marking the true entrance into what must surely be a sacred place.");
     set_exits(([
		"west"			: KEEPROOM"zforest/kratoan/road1.c",
		"east"			: KEEPROOM"zforest/kratoan/road3.c"
                ]));
     set_items(([
		"archway"	: "The archway is not made of cut wood but rather the trees on either side have grown together and tangled the branches, with creepers falling down between them. It is most beautiful."
		]));

        if(!present("monster")) {
        new(KEEPMOB"zforest/kratoan/sentry.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/sentry.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/sentry.c")->move(this_object());
	new(KEEPMOB"zforest/kratoan/denguard.c")->move(this_object());
	}
}
