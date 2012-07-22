#include <mjungle.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("Samul Ku'Thull");
set_short("%^BOLD%^YELLOW%^Samul Ku'Thull, the Merkkirri Warlord%^RESET%^");
set_long("Samul Ku'Thull is known throughout the lands as a devil among men.  He lives his life in supreme satisfaction of himself as he is the wielder of Starscream, one of the most powerful swords the Merkkirri have ever known.");
set("aggressive", 70);
set_id(({"gnoll", "warlord", "samul", "Samul", "Samul Ku'Thull", "samul ku'thull"}));
set_class("fighter");
set_subclass("antipaladin");
set_skill("blade", 300);
set_skill("attack", 300);
set_stats("strength", 120);
set_stats("dexterity", 100);
set_skill("faith", 145);
set_race("gnoll");
set_body_type("gnoll");
set_gender("male");
add_money("gold", (random(250)+250));
add_money("electrum", (random(250)));
set_skill("melee", 275);
set_skill("riding", 275);
new(MOB "darkmail.c")->move(this_object());
command("wear all");
new(MOB "starscream.c")->move(this_object());
command("wield sword");
new(MOB "warkey.c")->move(this_object());
set_languages("merkish");
set_speech(35,"merkish",({"How dare you attack a Merkkirri Warlord!",
"Its time for you to die!"}),1);
set_spell_chance(50);
set_spells(({"slash"}));
set_level(60);
set("alignment", -1000);
set_exp(300000);
}
