#include <std.h>
#include <lodos.h>
inherit MONSTER;
static int oi;

void create() {
 ::create();
   set_short("a royal samurai");
   set_id( ({ "samurai", "royal samurai" }) );
   set_name("samurai");
   set_level(29);
   set_long("One of Teque's personal elite bodyguard. The samurai "
      "stands ready to fight. Samurais are highly trained in the arts "
      "of combat.");
   set_body_type("human");
   set_race("human");
   set_gender("male");
   set_heart_beat(1);
   make(WEA"katana");
   make(WEA"katana");
}

void heart_beat() {
 ::heart_beat();
   if (!oi) { force_me("wield katana");
    force_me("wield katana 2"); oi = 1;}
}
