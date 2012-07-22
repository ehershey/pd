#include <std.h>
#include <aziraphale.h>
inherit ROOM;
void create() {
   ::create();
     set_properties((["light": 1, "night light" : 0, "forest" : 1]));
     set_short("Kra'Toa'Kathor");
     set_day_long("The clearing here has reached the entrance to a large temple standing just east of here, that path continues west. The strands of sunlight filtering through the trees high above is so beautiful at this spot that it is nearly blinding.");
     set_night_long("The clearing here has reached the entrance to a large temple standing just east of here, that path continues west. The strands of moonlight filtering through the trees high above is so beautiful at this spot that it is nearly blinding.");
     set_exits(([
                "west"                  : KEEPROOM"zforest/kratoan/road5.c",
                "east"                  : KEEPROOM"zforest/kratoan/temple.c",

                ]));
     set_items(([
                "temple" : "The temple is made entirely of trees that have simply grown to create a living cathedral."
                ]));

        if(!present("monster")) {
        new(KEEPMOB"zforest/kratoan/denguard.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/denguard.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/denguard.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/sentry.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/sentry.c")->move(this_object());
        new(KEEPMOB"zforest/kratoan/villager.c")->move(this_object());
        }
}
