#include <std.h>
#include <lodos.h>
inherit MONSTER;
static int oi;

void create() {
 ::create();
   set_short("a half-dragon warrior");
   set_id( ({ "half-dragon", "warrior", "half-dragon warrior" }));
   set_name("warrior");
   set_level(24);
   set_long("The half-dragon belongs to a small gang of fighters. She "
      "is strong and quick.");
   set_body_type("half-dragon");
   set_race("half-dragon");
   set_gender("female");
   set_heart_beat(1);
   set_alignment(200);
   make(ARM"wingarm");
}

void heart_beat() {
 ::heart_beat();
   if (!oi) {
     force_me("wear armour");
     oi = 1;
   }
}
