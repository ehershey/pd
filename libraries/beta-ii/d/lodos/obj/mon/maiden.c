#include <std.h>
#include <lodos.h>
inherit MONSTER;
static int oi;

void create() {
 ::create();
   set_short("a fair maiden");
   set_id( ({ "fair maiden", "maiden" }) );
   set_name("maiden");
   set_level(21);
   set_long("The fair maiden walks happily through the tiny garden, "
     "humming a happy tune. She seems happy with life, taking time "
     "to smell every flower.");
   set_body_type("human");
   set_race("human");
   set_gender("female");
   set_heart_beat(1);
   new(ARM"rdress")->move(this_object());
}

void heart_beat() {
 ::heart_beat();
  if (!this_object()) return;
   if (!oi) {this_object()->force_me("wear dress"); oi = 1; }
}
