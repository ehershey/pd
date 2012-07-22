#include <std.h>
#include <aziraphale.h>
inherit MONSTER;

void create() {
   ::create();
     set_name("Rhondale lookout guard");
     set_id( ({"guard", "monster", "lookout", "watcher"}) );
     set_short("Watcher");
     set_long("The watchers stand guard in the 4 towers of Rhondale, looking for any sign of trouble.");
     set_race("human");
     set_swarm(1);
     if (random(10) > 5)
        set_gender("female");
     else
        set_gender("male");
     set_body_type("human");
     set_level(35);
     new(KEEPWEAPON"zvillage/guardhammer.c")->move(this_object());
     force_me("wield hammer in right hand");
     new(KEEPWEAPON"zvillage/guardhammer.c")->move(this_object());
     force_me("wield hammer in left hand");
}
