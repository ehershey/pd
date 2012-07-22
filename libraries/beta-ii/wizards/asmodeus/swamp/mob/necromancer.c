#include <swamp.h>
#include <std.h>
inherit MONSTER;
int newbody();

void create() {
::create();
set_name("necromancer");
set_short("a merkkirri necromancer");
set_long("A strange and dark cult of merkkirri who not only follow the demon lord Asmodeus, but the god of death who's name few have ever learned.");
set("aggressive", 0);
set_id(({"necromancer", "gnoll", "merkkirri", "merkkirri necromancer"}));
set_skill("magic attack", 300);
set_class("mage");
set_subclass("necromancer");
set_alignment(-1000);
set_skill("necromancy", 300);
set_race("gnoll");
set_body_type("gnoll");
set_gender("male");
set_emotes(10, ({"The necromancer digs in the mud for bones.", "The gnoll mutters a few words.", "The necromancer coughs slightly."}),0);
set_spell_chance(40);
set_spells(({"soulburn", "chaoswave", "deathtouch"}));
set_level(55);
}
