#include <std.h>
#include <purgatory.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("Royal Assassin");
   set_short("Royal Assassin");
   set_id(({"assassin"}));
   set_long("%^BOLD%^%^BLACK%^Hard to see in any light, this assassin waits in the shadows to kill whomever tries to take down the King.  ");
   set_invis();
   set_level(65);
   set_class("rogue");
   set_subclass("assassin");
   set("aggressive", 25);
   set_skill("stealth", 390);
   set_spell_chance(40);
   set_gender("male" );
   set_race("raknid");
   set_heart_beat(1);
   set_body_type("raknid");
   set_spells(({"circle", "stab"}));


new(WEAP"sdagger")->move(this_object());
force_me("wield dagger");

new(WEAP"sdagger")->move(this_object());
force_me("wield dagger");

new(WEAP"sdagger")->move(this_object());
force_me("wield dagger");

new(WEAP"sdagger")->move(this_object());
force_me("wield dagger");
}


void init() {
   object *less;
   int i;
   ::heart_beat();
   less = all_inventory(environment(this_object()));
   i = sizeof(less);
   while (i--) {
     if (!less[i]->is_player()) continue;
     if (less[i]->is_player())
    call_out("kill_them", 15);
   return;
   }
}

kill_them() {
    message("info", "The <whatever> says: KILL THEM ALL!!",
object *all;
   int i;
   ::heart_beat();
   all = all_inventory(environment(this_object()));
   i = sizeof(all);
   while (i--) {
     if (!all[i]->is_player()) continue;
     if (all[i]->is_player())
   force_me("backstab "+all[i]->query_name());
}
}
