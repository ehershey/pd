#include <std.h>
#include <lodos.h>
inherit MONSTER;
static int oi;

void create() {
 ::create();
   set_short("a rich nobleman");
   set_id( ({ "noble", "nobleman" }) );
   set_name("noble");
   set_level(27);
   set_long("The rich noble wanders around the tower sneering at "
      "the servants.");
   set_emotes(0, ({ "The noble sneers at you." }), 0);
   set_body_type("human");
   set_race("elf");
   set_gender("male");
   set_heart_beat(1);
   make(ARM"clasp");
   make(ARM"cape");
}

void heart_beat() {
 ::heart_beat();
   if (!oi) { force_me("wear cape"); force_me("wear clasp"); oi = 1; }
}
