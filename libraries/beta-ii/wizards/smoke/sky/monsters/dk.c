#include <std.h>
#include <cp.h>
inherit MONSTER;

create() {
         ::create();
         set_name("deathknight");
         set_id(({ "deathknight" }));
         set_short("%^BOLD%^%^BLACK%^deathknight%^RESET%^");
         set_long("%^BOLD%^%^BLACK%^This undead creature roams the bowels of "
                 "the castle. His face lacks flesh and a %^RESET%^%^RED%^fire%^ "
                 "%^BOLD%^%^BLACK%^burns deep in his eyes.");
         set_race("undead");
         set_class("fighter");
         set_subclass("warrior");
         set_body_type("human");
         set("aggressive", 40);
         set_stats("strength", 150);
         set_gender("male");
         set_level(65);
         set_spell_chance(20);
         set_spells(({"slash", "rush"}));
    new(WEAP"dfsword.c")->move(this_object());
    command("wield sword");

}

