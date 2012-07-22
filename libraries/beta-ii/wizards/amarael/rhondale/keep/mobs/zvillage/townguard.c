#include <std.h>
#include <aziraphale.h>
inherit MONSTER;

void create() {
   ::create();
     set_name("Rhondale guard");
     set_id( ({"guard", "monster"}) );
     set_short("Town guard");
     set_long("A member of the town guard that keeps peace in Rhondale.");
     set_race("human");
     set_swarm(1);
     if (random(10) > 5)
        set_gender("female");
     else
        set_gender("male");
     set_body_type("human");
     set_level(35);
     new(KEEPWEAPON"zvillage/guardsword.c")->move(this_object());
     force_me("wield sword in right hand");
     new(KEEPWEAPON"zvillage/guardsword.c")->move(this_object());
     force_me("wield sword in left hand");
}
