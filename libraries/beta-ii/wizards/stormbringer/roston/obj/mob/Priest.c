#include <std.h>
#include <roston.h>
inherit MONSTER;

int wielded_sword=0;
void create() {
    ::create();
    set_name("Priest");
    set_short("Holy Priest");
    set_long("The Priest is a very holy man, he loves "
      "all people. He is very wise, and strong. "
      "The priest lives in the Church, he will die "
      "over protecting his church.");
    set_id(({"priest", "wise priest"}));
    set_level(40);
    set_race("dwarf");
    set_alignment(1500);
    set_class("cleric");
    set_spell_chance(100);
    set_spells( ({"paralyze"}) );
    set_skill("healing", 100);
    set_body_type("human");
    set_gender("male");
    new(ARM"shield")->move(this_object());
    new(ARM"helmet")->move(this_object());
    new(WEP"staff")->move(this_object()); 


    set_heart_beat(1);
    if(random(200) > 190) {
	new("/wizards/daboura/arm/dull_brass_chest_plate.c")->move(this_object());
	command("wear plate");
    }
}                                             
void init()   
{
    ::init();
}

void heart_beat()
{
    ::heart_beat();
    if (!wielded_sword)
    {
	this_object()->force_me("wear helm");
	this_object()->force_me("wield staff");
	this_object()->force_me("wear shield");
	wielded_sword = 1;
    }
}




