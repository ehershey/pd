#include <mjungle.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("sahuun");
set_short("%^BOLD%^YELLOW%^Sahuun, the Merkkirri Blood Warlord%^RESET%^");
set_long("Sahuun has been head of the blood warriors since the coming of the current queen.  His loyalty to the Queen is one of his few admirable traits.");
set_class("fighter");
set_subclass("warrior");
set("aggressive", 40);
set_id(({"gnoll", "warlord", "sahuun", "Sahuun", "blood warlord", "warrior", "blood warrior"}));
set_skill("attack", 275);
set_stats("strength", 100);
set_stats("dexterity", 100);
set_skill("faith", 145);
set_race("gnoll");
set_body_type("gnoll");
set_gender("male");
add_money("gold", (random(50)+50));
add_money("electrum", (random(250)));
set_skill("melee", 275);
new(MOB "shadowhelm.c")->move(this_object());
command("wear all");
set_languages("merkish");
set_spell_chance(50);
set_skill("blunt", 275);
set_spells(({"maul"}));
set("alignment", -1000);
set_level(50);
new(MOB "obsidianmace.c")->move(this_object());
command("wield mace");
}
