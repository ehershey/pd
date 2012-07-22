#include <mjungle.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("warlock");
set_short("Merkkirri Warlock");
set_long("The Merkkirri gnolls make this part of the jungle their home.  While gnolls aren't well known for their magical abilites, some Merkkirri are actually quite learned in the arts of magic.  This particular gnoll has made her home high in the tree where she can run her experiements in peace and solitude.");
set_id(({"gnoll", "warlock", "merkkirri", "merkkirri warlock", "merkkirri gnoll"}));
set_skill("magic attack", 125);
set_skill("magic defense",75);
set_stats("intelligence", 50);
set_stats("wisdom", 40);
set_race("gnoll");
set_body_type("gnoll");
set_gender("female");
add_money("gold", (random(200)));
add_money("electrum", (random(75)));
set_emotes(10, ({"The warlock stares at you waiting for you to make a move.", "The warlock grips her staff in anticipation of battle."}),0);
set_spell_chance(40);
set_spells(({"scorch", "burn"}));
set_languages("merkish");
set_speech(40,"merkish",({"Why do you wish to die so young!?", "You can not match my power!", "Die maggot!"}),1);
set_class("mage");
set_subclass("pyromancer");
set_level(27);
set("alignment", -1000);
new(MOB "s_robes.c")->move(this_object());
new(MOB "morstaff.c")->move(this_object());
command("wield staff");
command("wear robes");
}
