#include <std.h>
#include <lodos.h>
inherit MONSTER;
static int oi;

void create() {
 ::create();
   set_short("a centaur");
   set_id(({ "centaur" }));
   set_name("centaur");
   set_level(23);
   set_long("The centaur is in very good shape and trots around, swinging "
      "at the air, shadowboxing. He looks like a well trained fighter.");
   set_body_type("centaur");
   set_race("centaur");
   set_gender("male");
   set_heart_beat(1);
   set_alignment(20);
   make(ARM"tailties");
   make(ARM"horseshoes");
   make(ARM"saddle");
}

void heart_beat() {
 ::heart_beat();
   if (!oi) {
     force_me("wear ties");
     force_me("wear shoes");
     force_me("wear saddle");
     oi = 1;
   }
}
