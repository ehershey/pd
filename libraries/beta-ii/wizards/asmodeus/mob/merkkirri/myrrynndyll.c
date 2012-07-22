#include <mjungle.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("Myrrynndyll");
set_short("Myrrynndyll, demonic servant of Shallzaea");
set_long("Myrrynndyll is a nether demon bound to Shallzaea.  It appears as a large, obsidian skinned humanoid with protruding horns at the temples, large bat-like wings and a spiked tail.");
set("aggressive", 50);
set_id(({"myrrynndyll", "Myrrynndyll", "demon", "nether demon"}));
set_skill("magic attack", 250);
set_class("kataan");
set_skill("healing", 50);
set_alignment(-1000);
set_skill("faith", 250);
set_skill("magic defense",75);
set_stats("intelligence", 85);
set_stats("wisdom", 100);
set_race("demon");
set_body_type("demon");
set_gender("neuter");
set_spell_chance(40);
set_spells(({"demonbolt", "shadowburst", "hellfire", "massacre", "gore"}));
set_lang_prof("merkish", 10);
set_speech(50,"merkish",({"My lord will have less mercy on you than I...", "Death will be the most pleasurable part of your fate!", "Feel the powers of Hell upon you!"}),1);
new(MOB "snakebandring.c")->move(this_object());
command("wear ring");
set_level(50);
set_exp(365000);
}
