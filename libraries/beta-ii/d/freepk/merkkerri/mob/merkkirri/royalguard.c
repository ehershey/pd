#include <mjungle.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("royal guard");
set_short("Merkkirri Royal Guard");
set_long("The Merkkirri Royal Guard is a highly exhaulted position among the people of Quixxiol.  It takes years of training, battle and loyalty to even have a chance of attaining this rank.  All are worthy opponents.");
set_id(({"gnoll", "royal guard", "merkkirri royal guard" ,"guard", "merkkirri", "merkkirri guard", "merkkirri gnoll"}));
set_level(33);
set_swarm("guard");
set("aggressive", 30);
set_heart_beat(1);
set_race("gnoll");
set_body_type("gnoll");
set_gender("male");
add_money("gold", (random(50)));
add_money("electrum", (random(75)));
set_emotes(10, ({"The guard grips his spear a bit tighter.", "The guard shifts slightly."}),0);
set_class("fighter");
set_subclass("warrior");
set_spell_chance(40);
set_spells(({"parry", "headbutt", "rush"}));
new(MOB "banded")->move(this_object());
command("wear armor");
new(MOB "royalcape.c")->move(this_object());
command("wear cape");
new(MOB "merkspear")->move(this_object());
command("wield spear");
set_languages("merkish");
set_speech(10,"merkish",({"The Merkkirri must not fall!", "Death to our enemies!", "Intruder! Intruder!"}),1);
set("alignment", -1000);

}
