#include <mjungle.h>
#include <std.h>
inherit UNDEAD;

void create() {
    ::create();
    set_name("warrior");
    set_short("Undead Warrior");
    set_long("The Merkkirri gnolls have buried their dead in catacombs such as this for ages.  Occasionally the Merkkirri Necromancers will come to the crypts and raise the dead to help fight alongside the Blood Warriors.");
    set_id(({"undead", "undead warrior", "warrior"}));
    set_race("undead");
    set_body_type("gnoll");
    set_class("fighter");
    set_subclass("warrior");
    set_skill("blade", 190);
    set_gender("male");
    add_money("gold", (random(50)));
    add_money("electrum", (random(75)));
    set_spell_chance(40);
    set_spells(({"parry", "slash"}));
    new(MOB "banded")->move(this_object());
    command("wear armor");
    new(MOB "scimitar.c")->move(this_object());
    command("wield scimitar");
    new(MOB "scimitar.c")->move(this_object());
    command("wield scimitar");
    set_level(25);

    set("alignment", -1000);
}
