#include <std.h>
inherit MONSTER;

void create() {
::create();
    set_name("guard");
    set_short("Crimson Guard");
    set_long("This is the fabled Crimson Guard. It is rumored that he "
        "guards the entrance to the Gehenna.");
    set_id(({"guard", "crimson guard"}));
    set_race("Demon");
    set_body_type("human");
    set_gender("male");
    set_spell_chance(35); 
    set_spells(({"slash"}));
set_class("fighter");
set_subclass("knight");
    set_level(32);
    set_stats("stregnth", 50);
    set_stats("constitution", 50);

new("/wizards/marduk/hell/crim_arm.c")->move(this_object());
this_object()->force_me("wear armor");
new("/wizards/marduk/hell/crim_helm.c")->move(this_object());
this_object()->force_me("wear helm");
new("/wizards/marduk/hell/crim_sword.c")->move(this_object());
this_object()->force_me("wield sword");
new("/wizards/marduk/hell/f_key.c")->move(this_object());
}
