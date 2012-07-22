#include <std.h>
#include <lodos.h>
inherit MONSTER;
static int oi;

void create() {
 ::create();
   set_short("Teque, the blood baron");
   set_id( ({ "teque", "baron", "warlord", "blood baron" }) );
   set_name("warlord");
   set_level(28);
   set_long("The most famous warlord of the otherwise peaceful Lodos "
      "is Teque. He is also known as the blood baron, because of his "
      "bloody method of conquring land.");
   set_body_type("human");
   set_race("human");
   set_gender("male");
   set_heart_beat(1);
   set_alignment(-600);
   make(WEA"bblade");
if(random(200) > 195) {
   new("/wizards/daboura/arm/dull_brass_gloves.c")->move(this_object());
   command("wear gloves");
}
}

void heart_beat() {
 ::heart_beat();
   if (!oi) {
     force_me("wield blade");
     oi = 1;
   }
}
