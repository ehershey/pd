#include <std.h>
#include <mjungle.h>

inherit MONSTER;

void create() {
::create();
set_name("warrior");
set_short("Merkkirri Blood Warrior");
set_long("The Merkkirri gnolls make this part of the jungle their home.  The "
"Blood Warriors are the faction within the settlement responsible for raiding "
"and plundering nearby villages."); 
set_id(({"gnoll", "merkkiirri", "merkkirri warrior", "merkkirri blood warrior", "blood warrior"}));
set_level(27);
set_class("fighter");
set_subclass("warrior");
set("aggressive", 16);
set_skill("blade", 120);
set_skill("attack", 90);
set_skill("melee", 90);
set_race("gnoll");
set_body_type("gnoll");
set_gender("male");
set_heart_beat(1);
add_money("gold", (random(50)));
add_money("electrum", (random(75)));
set_spell_chance(30);
set_spells(({"rush", "choke"}));
new(MOB "blacksteel_br")->move(this_object());
new(MOB "blacksteel_bl")->move(this_object());
force_me("wear all");
new(MOB "sssword.c")->move(this_object());
force_me("wield sword");
new(MOB "sssword.c")->move(this_object());
force_me("wield sword ");
set_languages("merkish");
set_speech(10,"merkish",({"The Merkkirri must not fall!", "Death to our enemies!", "Intruder! Intruder!"}),1);
}
