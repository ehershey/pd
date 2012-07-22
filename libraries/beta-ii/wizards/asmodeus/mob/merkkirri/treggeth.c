#include <mjungle.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("treggeth");
set_short("%^BOLD%^YELLOW%^Treggeth, the Merkkirri Warlord%^RESET%^");
set_long("Treggeth is quite large for his race. He bears the scars of many battles and he wears the trophies of many victories.  He holds in his hand a horrifying axe with four large blades.");
set("aggressive", 16);
set_id(({"gnoll", "warlord", "treggeth", "treggeth, the merkkirri warlord"}));
set_skill("axe", 190);
set_skill("attack", 180);
set_stats("strength", 65);
set_stats("dexterity", 60);
set_race("gnoll");
set_body_type("gnoll");
set_gender("male");
add_money("gold", (random(250)));
add_money("electrum", (random(250)));
set_skill("melee", 175);
new(MOB "blacksteel_br")->move(this_object());
new(MOB "blacksteel_bl")->move(this_object());
new(MOB "sp_plate")->move(this_object());
command("wear all");
new(MOB "merkaxe.c")->move(this_object());
command("wield axe");
set_languages("merkish");
set_speech(35,"merkish",({"How dare you attack a Merkkirri Warlord!",
"Your death will serve my lord well!", "Taste the pain of my axe!"}),1);
set_level(32);
set("alignment", -1000);
set_exp(96000);
}
