#include <mjungle.h>
#include <gcity.h>
#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("shallzaea");
set_short("Shallzaea, the Demon mistress");
set_long("Shallzaea is actually a demon in disguise as a gnoll!  Her body is sleek and black, her wings large and imposing and her eyes burn with the flames of Hell!");
set("aggressive", 666);
set_id(({"shallzaea", "queen", "merkkirri queen", "the merkkirri queen", "demon"}));
set_skill("magic attack", 500);
set_class("kataan");
set_alignment(-1000);
set_skill("faith", 500);
set_stats("intelligence", 175);
set_stats("wisdom", 200);
set_race("demon");
set_body_type("demon");
set_gender("female");
set_spell_chance(50);
set_spells(({"massacre", "gore"}));
set_lang_prof("merkish", 10);
set_speech(50,"demonish",({"You know my secret, you must die!", "Your death is unavoidable now...", "My power is infinate!", "Wretched creature!", "Feel the wrath of a true demon!"}),1);
set_level(70);
new(MOB "cloakofmidnight.c")->move(this_object());
command("wear cloak");
new(GCITY "ruby_key.c")->move(this_object());
set_exp(800000);
}

void init()   
{
 ::init();
}

void catch_tell(string str) {
   string person;
   if (!sscanf(lower_case(str), "%s dies a horrible death.", person)) return;
   if (!find_player(person)) return;
   message("info", "%^BOLD%^MAGENTA%^Shallzaea shouts:%^RESET%^ The soul "
     "of "+capitalize(person)+" shall serve my lord well!",
users());
}
