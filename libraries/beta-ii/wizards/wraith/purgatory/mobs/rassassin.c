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
   set_skill("attack", 325);
   set_skill("defense", 260);
   set_skill("double wielding", 325);
   set_skill("agility", 325);
   set_skill("murder", 325);
   set_skill("stealth", 390);
   set_spell_chance(40);
   set_skill("perception", 260);
   set_skill("knife", 325);
   set_skill("stealing", 325);
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
   object *all;
   int i;
   ::heart_beat();
   all = all_inventory(environment(this_object()));
   i = sizeof(all);
   while (i--) {
     if (!all[i]->is_player()) continue;
     if (all[i]->is_player())
        force_me("backstab "+all[i]->query_name());
   return;
   }
}

