#include <std.h>
#include <lodos.h>
inherit MONSTER;
static int oi;

void create() {
 ::create();
   set_short("a prisoner");
   set_id(({ "prisoner" }));
   set_name("prisoner");
   set_level(24);
   set_long("The prisoner leans against the back wall, looking at you. "
     "His fists are clenched. He looks angry.");
   set_body_type("human");
   set_race("orc");
   set_gender("male");
   set_heart_beat(1);
   make(WEA"knuckles");
}

void heart_beat() {
 ::heart_beat();
   if (!oi) {
      force_me("wield knuckles");
      force_me("growl");
      oi = 1;
   }
}
