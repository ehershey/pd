#include <std.h>
inherit MONSTER;

void create() {
::create();
set_name("guard");
set_short("Possessed Guard");
set_long("The Elven guard looks neither alive nor dead. It's eyes "
    "glow with a deep %^RED%^hatred %^RESET%^for all living. ");
set_id(({"guard", "possessed guard", "monster"}));
set_level(25);
set_heart_beat(1);
set_skill("blade", 150);
set_skill("attack", 110);
set_race("elf");
set_body_type("elf");
set_gender("male");
set_spell_chance(40);
set_spells(({"whirl"}));
set_class("fighter");
set_subclass("knight");
    set_level(32);
    set_stats("stregnth", 65);
    set_stats("dexterity", 65);

new("/wizards/marduk/gehenna/j_sword.c")->move(this_object());
this_object()->force_me("wield sword");
new("/wizards/marduk/gehenna/ic_boots.c")->move(this_object());
this_object()->force_me("wear boots");
new("/wizards/marduk/gehenna/sk_helm.c")->move(this_object());
this_object()->force_me("wear helm");
}
