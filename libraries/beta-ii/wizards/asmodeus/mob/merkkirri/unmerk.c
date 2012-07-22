#include <mjungle.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("warrior");
set_short("Undead Warrior");
set_long("The Merkkirri gnolls have buried their dead in catacombs such as this for ages.  Occasionally the Merkkirri Necromancers will come to the crypts and raise the dead to help fight alongside the Blood Warriors.");
set_id(({"undead", "undead warrior", "warrior"}));
set_heart_beat(1);
set_skill("blade", 125);
set_skill("attack", 125);
set_stats("strength", 50);
set_stats("dexterity", 50);
set_race("gnoll");
set_body_type("gnoll");
set_gender("male");
add_money("gold", (random(50)));
add_money("electrum", (random(75)));
set_spell_chance(40);
set_spells(({"parry", "whirl", "slash"}));
new(MOB "banded")->move(this_object());
command("wear armor");
new(MOB "scimitar.c")->move(this_object());
command("wield scimitar");
new(MOB "scimitar.c")->move(this_object());
command("wield scimitar");
set_level(25);
set_exp(59000);
set("alignemnt", -1000);
}
