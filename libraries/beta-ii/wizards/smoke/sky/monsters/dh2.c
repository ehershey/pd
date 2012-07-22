#include <std.h>
#include <cp.h>
inherit MONSTER;

create() {
         ::create();
         set_name("dragon hunter");
         set_id(({ "hunter", "dragon hunter" }));
         set_short("Dragon hunter");
         set_long("This fearless guy is hunting dragons with "
                 "nothing more than a few swords and a loincloth.");
         set_race("ogre");
         set_class("fighter");
         set_subclass("warrior");
         set_body_type("troll");
         set("aggressive", 75);
         set_stats("strength", 200);
         set_gender("male");
         set_level(70);
         set_spell_chance(40);
         set_spells(({"slash", "rush"}));
    new(WEAP"dfsword.c")->move(this_object());
    command("wield sword");
    new(WEAP"dfsword.c")->move(this_object());
    command("wield sword");
}
