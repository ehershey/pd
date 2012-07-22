#include <mjungle.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("renegade");
set_short("Blacktooth Renegade");
set_long("The Blacktooth Renegades are a band of outcasts who secretly plot the "
"takeover of the Merkkirri.  Their numbers are small but their members are "
"cunning and powerful.");
set_id(({"gnoll", "blacktooth", "renegade", "outcast"}));
set_level(35);
set("aggressive", 24);
set_race("gnoll");
set_body_type("gnoll");
set_gender("female");
add_money("gold", (random(50)));
add_money("electrum", (random(75)));
set_emotes(10, ({"The renegade grips her daggers tightly.", "The blacktooth crouches down slightly into a strange combat stance."}),0);
set_spell_chance(40);
set_spells(({"whirl", "slash"}));
new(MOB "scalemail")->move(this_object());
force_me("wear armor");
if(random(200) > 5) {
new(MOB "ivorydagger")->move(this_object());
force_me("wield dagger");
new(MOB "ivorydagger")->move(this_object());
force_me("wield dagger");
}
else {
new("/wizards/daboura/black_dagger.c")->move(this_object());
force_me("wield dagger");
}
set_languages("merkish");
set_speech(25, "merkish", ({"For the Blacktooth!", "May the maggots enjoy your bodies!"}),1);
set_alignment(0);
}
