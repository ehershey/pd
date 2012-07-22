#include <std.h>
inherit MONSTER;

void create() {
::create();
    set_name("assassin");
    set_short("Salazar");
    set_long("Salazar is the result of an experiment gone horribly wrong. "
	"He is half-artrell, and half-elf. He lays here in wait for weak "
        "mortals to prey upon.");
    set_id(({"salazar", "artrell", "assassin"}));
    set_race("artrell-half-elf");
    set_body_type("artrell");
    set_gender("male");
    set_spell_chance(50);
    set_spells(({"stab"}));
    set_class("rogue");
    set_subclass("assassin");
    set_level(38);
    set_skill("knife", 160);
    set_skill("attack", 160);
    set_skill("double wielding", 160);
    set_stats("dexterity", 70);

new("/wizards/marduk/hell/tw_dagger.c")->move(this_object());
this_object()->force_me("wield dagger");
new("/wizards/marduk/hell/tw_dagger.c")->move(this_object());
this_object()->force_me("wield dagger");
new("/wizards/marduk/hell/tw_dagger.c")->move(this_object());
this_object()->force_me("wield dagger");
new("/wizards/marduk/hell/tw_dagger.c")->move(this_object());
this_object()->force_me("wield dagger");
new("/wizards/marduk/hell/coc_cloak.c")->move(this_object());
this_object()->force_me("wear cloak");
}
