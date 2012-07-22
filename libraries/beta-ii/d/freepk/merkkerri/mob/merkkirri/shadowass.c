#include <mjungle.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("assailant");
set_short("dark assailant");
set_long("A shadowy figure hiding in the room!  You have no idea how long it has been watching you!");
set_id(({"shadow", "assailant", "dark assailant", "assassin", "figure"}));
set_invis();
set_skill("murder", 200);
set_skill("stealth", 250);
set_class("rogue");
set_alignment(-1000);
set_skill("magic defense",75);
set_stats("intelligence", 90);
set_stats("wisdom", 85);
set_race("gnoll");
set_body_type("gnoll");
set_gender("male");
set_level(40);
set_subclass("assassin");
set_skill("knife", 400);
set_skill("attack", 275);
set_emotes(1, ({"You thought you heard a noise but you don't see the source anywhere."}),0);
set_spell_chance(50);
set_spells(({"stab"}));
set_lang_prof("merkish", 10);
set_speech(50,"merkish",({"I'll cut out yer eyes and widen your smile!", "Oh the maggots will enjoy their feast tonight!"}),1);
new(MOB "bloodstonedagger.c")->move(this_object());
new(MOB "bloodstonedagger.c")->move(this_object());
command("wield dagger");
command("wield dagger 2");

}
