#include <std.h>
inherit MONSTER;

void create() {
::create();
    set_name("guard");
    set_short("Crimson Guard");
    set_long("This is the fabled Crimson Guard. They stand guard over "
        "over all who enter Gehenna");
    set_id(({"guard", "crimson guard"}));
    set_race("Demon");
    set_body_type("human");
    set_gender("male");
    set_spell_chance(35); 
    set_spells(({"slash"}));
set_class("fighter");
set_subclass("knight");
    set_stats("stregnth", 50);
    set_level(40);
    set_stats("constitution", 50);

new("/wizards/marduk/hell/crim_arm.c")->move(this_object());
this_object()->force_me("wear armor");
new("/wizards/marduk/hell/crim_helm.c")->move(this_object());
this_object()->force_me("wear helm");
new("/wizards/marduk/hell/crim_sword.c")->move(this_object());
new("/wizards/marduk/hell/crim_gloves.c")->move(this_object());
this_object()->force_me("wear gloves");
new("/wizards/marduk/hell/crim_boots.c")->move(this_object());
this_object()->force_me("wear boots");
this_object()->force_me("wield sword");
}
