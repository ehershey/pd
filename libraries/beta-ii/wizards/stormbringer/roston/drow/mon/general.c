#include <std.h>
#include <roston.h>
inherit MONSTER;
int wielded_sword=0;
void create() {
::create();
    set_name("General");
    set_short("%^BOLD%^%^WHITE%^Meroini, General of the Drow Army");
    set_long("As you look Meroini over you are over taken "
    "by her grace and charm. She stands almost six feet tall, and "
    "she has deep black eyes, and long black hair. She is feared by "
    "every man in the lands. She wears her helm proudly, "
    "as it was a gift from her slain mother.");
    set_id(({"meroini", "general","meroini general of the drow army"}));
    set_race("drow");
    set_class("fighter");
    set("aggressive", 40);   
    set_subclass("warrior");
    set_spell_chance(45);
    set_skill("attack", 525);
    set_skill("defense", 525);
    set_skill("double wielding", 525);
    set_skill("blade", 525);
    set_skill("riding", 900);
    set_spells( ({"rush","slash"}) );
    set_level(99);
    set_swarm(1);
    set_body_type("human");
    set_gender("female");
    add_alignment(-1500);
    new(DROWOBJ"d_drow")->move(this_object());
    new(DROWOBJ"d_boots")->move(this_object());
    new(DROWOBJ"d_gloves")->move(this_object()); 
    new(DROWOBJ"g_sword")->move(this_object());
    new(DROWOBJ"g_sword")->move(this_object());
    new(ROSTON"cave/lava/helm")->move(this_object());
    set_heart_beat(1);
   set_exp(560000);
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
    this_object()->force_me("wear armour");
    this_object()->force_me("wear gauntlets");
    this_object()->force_me("wear boots");
    this_object()->force_me("wear helm");
    this_object()->force_me("wield sword");
    this_object()->force_me("wield sword 2");
    wielded_sword = 1;
   }
}
