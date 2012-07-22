#include <std.h>
#include <arlon2.h>
inherit "/std/police.c";
int oi = 0;
void create()
{
 ::create();
 set_name("Guard");
 set_id(({"guard", "cityguard", "city guard" }));
 set_short("A member of the Arlon city guard");
 set_long("The city guard is a tall and strong looking human.  The guard is a police officer who you do not want to mess with.");
 set_race("human");
if (random(10) >  5)
 set_gender("female");
else
 set_gender("male");
 set_body_type("human");
 set_level(30);
 set_max_hp(2000);
 set_hp(2000);
  set_swarm(1);
 set_heart_beat(1);
 new(WEP"woodenstaff")->move(this_object());
}
void heart_beat() {
 ::heart_beat();
 if (!oi) {
 command("wield staff"); 
 oi = 1;
 }
}

