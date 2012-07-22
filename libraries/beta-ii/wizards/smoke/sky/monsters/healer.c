#include <std.h>
#include <cp.h>
inherit MONSTER;

create() {
         ::create();
         set_name("dwarven healer");
         set_id(({ "dwarf", "healer", "dwarven healer" }));
         set_short("dwarven healer");
         set_long("The healer has a strong sense of belief. Her faith "
                 "is strong and her healing powers are a gift from her "
                 "god. She is in the monestary praying to her god, asking "
                 "to learn new spells to help the dwarven race.");
         set_race("dwarf");
         set_class("clergy");
         set_subclass("cleric");
         set_body_type("dwarf");
         set("aggressive", 50);
         set_gender("female");
         set_level(82);
set_spell_chance(60);
         set_spells(({"paralyze", "cure me", "wound"}));
    new(ARM"healerrobe.c")->move(this_object());
    command("wear robe");
    new(ARM"sandals.c")->move(this_object());
    command("wear sandals");
}
