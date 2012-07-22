#include <mjungle.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("olsar");
set_short("Olsar, the Blood Warrior Commander");
set_long("Olsar is a large gnoll and is quite well known among his people.  Olsar has conducted several highly successful raids against nearby villages.");
set("aggressive", 30);
set_swarm("");
set_id(({"gnoll", "commander", "warrior", "olsar", "blood warrior commander", "blood warrior", "merkkirri"}));
set_skill("blade", 200);
set_skill("attack", 200);
set_stats("strength", 75);
set_stats("dexterity", 75);
set_race("gnoll");
set_body_type("gnoll");
set_gender("male");
add_money("gold", (random(250)));
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
set_exp(200000);
}
