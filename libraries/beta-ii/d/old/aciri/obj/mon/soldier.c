#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
::create();
    set_name("acirian soldier");
    set_short("An Acirian Soldier");
    set_long("The soldier is relatively inequiped for battle.  He is young "
         "and relatively weak, willing to give his life for his people.  The "
         "markings on his face look tribal. ");
    set_id(({"soldier", "acirian soldier"}));    
    set_level(20);
    set_race("human");
    set_body_type("human");
    set_gender("male");
    set_class("fighter");
    set_spell_chance(20);       
    set_spells(({"slash", "whirl"}));
new(WEA "aciriansword.c")->move(this_object());
    command("wield sword");

new(ARM "acirianarmor.c")->move(this_object());
    command("wear armor");    

}

