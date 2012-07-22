#include <std.h>
#include <lodos.h>
inherit MONSTER;
static int oi=0;

void create() {
 ::create();
   set_short("Pipiel the gardener");
   set_id( ({ "pipiel", "gardener" }) );
   set_name("pipiel");
   set_level(16);
   set_long("Pipiel stands here, looking over his garden and rather "
     "enjoying life.");
   set_body_type("human");
   set_race("human");
   set_gender("male");
   set_heart_beat(1);
   make(WEA"shears");
   oi = 0;
}

void heart_beat() {
 ::heart_beat();
   if (!oi) {
     force_me("wield shears");
     oi = 1;
   }
}
