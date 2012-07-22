
#include <mjungle.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("cleric");
set_short("Merkkirri Black Cleric");
set_long("The Black Clerics of the Merkkirri are a twisted and evil group. 
Their rituals involve the use of blood and sacrifice and are often followed by
raids on villages by the Blood Warriors.");
set_id(({"gnoll", "merkkirri", "merkkirri black cleric", "black cleric",
"cleric"}));
set_level(37);
set_race("gnoll");
set_body_type("gnoll");
set_gender("female");
add_money("gold", (random(200)));
add_money("electrum", (random(75)));
set_emotes(10, ({"The Black Cleric meets your gaze with cold black eyes.", "The
Black Cleric mutters a few words."}),0);
set_class("cleric");
set_spell_chance(35);
set_spells(({"lifetap", "paralyze"}));
set_languages("merkish");
set_speech(50,"merkish",({"My god will destroy you!", "Vengence and spite keep
me alive!", "The Merkkirri are the chosen ones!"}),1);
new(MOB "s_robes.c")->move(this_object());
new(MOB "crystalkey.c")->move(this_object());
command("wear robes");
}
