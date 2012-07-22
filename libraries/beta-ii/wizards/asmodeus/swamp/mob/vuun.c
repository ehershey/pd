
#include <swamp.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("Vuun");
set_short("Vuun, the raknid champion");
set_long("Vuun appears as a slightly wounded raknid warrior standing nearly 2.5 meters tall.  Raknid champions are extremely ferocious and even more so if near a colony...");
set("aggressive", 60);
set_id(({"raknid", "vuun", "Vuun", "champion"}));
set_class("fighter");
set_subclass("warrior");
set_alignment(0);
set_race("raknid");
set_body_type("raknid");
set_gender("male");
set_spell_chance(60);
set_spells(({"slash"}));
set_level(60);
new(MOB "exoskeleton")->move(this_object());
command("wear exoskeleton");
new(MOB "hsaber.c")->move(this_object());
command("wield saber");
new(MOB "hsaber.c")->move(this_object());
command("wield saber");
new(MOB "hsaber.c")->move(this_object());
command("wield saber");
new(MOB "hsaber.c")->move(this_object());
command("wield saber");
}


void heart_beat() {
 int i;
 object env, ob, *all;
 ::heart_beat();
   if (!this_object()->query_current_attacker()) return;
   if (random(3000) > 400) return;
   ob = this_object()->query_current_attacker();
   env = environment(ob);
   switch (random(2)) {
     case 1:  // acid
       tell_object(env, "%^BOLD%^MAGENTA%^Vuun %^RED%^SPRAYS%^MAGENTA%^ his victim with a horrific acid!");
       ob->damage(random(100)+600);
       break;
     default: // pierce
       tell_object(env, "%^BOLD%^MAGENTA%^Vuun %^BLACK%^PIERCES%^MAGENTA%^ his victim deeply with his leg!");
      ob->damage(random(100)+700);
   }
}
