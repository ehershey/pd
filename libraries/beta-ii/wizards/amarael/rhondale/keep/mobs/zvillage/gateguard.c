#include <std.h>
#include <aziraphale.h>
inherit MONSTER;

void create() {
   ::create();
     set_name("Rhondale gate guard");
     set_id( ({"guard", "monster"}) );
     set_short("The gate guard");
     set_long("This member of the guard is stationed at the town gates.");
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
