#include <mjungle.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("neslem");
set_short("Neslem, the Blood Warrior Commander");
set_long("Neslem is getting rather old and his days as a commander are numbered.  He does however still have his uses to the Blood Warriors.");
set("aggressive", 20);
set_swarm("");
set_id(({"gnoll", "commander", "warrior", "neslem", "blood warrior commander", "blood warrior", "merkkirri"}));
set_stats("strength", 75);
set_stats("dexterity", 75);
set_race("gnoll");
set_body_type("gnoll");
set_gender("male");
add_money("gold", (random(50)));
add_money("electrum", (random(250)));
set_skill("melee", 175);
set_spell_chance(47);
set_spells(({"slash", "sharpen sword"}));
set_class("fighter");
set_subclass("soldier");
set_skill("riding", 200);
new(MOB "blacksteel_br")->move(this_object());
new(MOB "blacksteel_bl")->move(this_object());
new(MOB "sp_plate")->move(this_object());
command("wear all");
set_level(40);
set_skill("blade", 250);
new(MOB "esword.c")->move(this_object());
command("wield sword");
new(MOB "esword.c")->move(this_object());
command("wield sword");
set_languages("merkish");
set("alignment", -1000);

}
