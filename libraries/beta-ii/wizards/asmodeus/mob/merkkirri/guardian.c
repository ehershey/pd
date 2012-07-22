#include <mjungle.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("guardian");
set_short("Guardian of the Tomb");
set_long("The guardian is a shadowy blue spectre.  Its eyes are a firey orange and it wears the clothing of an ancient Merkkirri warrior.");
set("aggressive", 30);
set_id(({"guardian", "spectre", "guardian of the tomb"}));
set_skill("magic attack", 200);
set_skill("healing", 50);
set("alignment", -1000);
set_skill("magic defense",75);
set_skill("conjuring", 150);
set_race("gnoll");
set_stats("intelligence", 60);
set_stats("wisdom", 60);
set_body_type("gnoll");
set_gender("male");
set_class("mage");
set_subclass("pyromancer");
set_emotes(10, ({"The guardian's eyes glow brightly.", "The guardian nearly fades from view."}),0);
set_spell_chance(45);
set_spells(({"shroud", "scorch", "burn"}));
set_lang_prof("merkish", 10);
set_speech(30,"merkish", ({"The winds of death both burn and freeze...", "Entering our place of rest was a mistake...", "Join our suffering..."}),1);
set_level(30);
new(MOB "cryptkey.c")->move(this_object());
set_exp(97000);
}
