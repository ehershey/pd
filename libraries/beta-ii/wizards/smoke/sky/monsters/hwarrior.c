#include <std.h>
#include <cp.h>
inherit MONSTER;

create() {
         ::create();
         set_name("holy warrior");
         set_id(({ "warrior" }));
         set_short("%^YELLOW%^holy warrior%^RESET%^");
         set_long("%^YELLOW%^This spiritual being defends the realm of "
                 "those who wish to harm it. A strong aura radiates off "
                 "the warrior, as if to signify holiness.%^RESET%^");
         set_race("spirit");
         set_class("fighter");
         set_subclass("warrior");
         set_body_type("human");
         set("aggressive", 40);
         set_stats("strength", 150);
         set_gender("male");
         set_level(70);
         set_spell_chance(20);
         set_spells(({"massacre", "rush"}));
    new(ARM"dscaleboots.c")->move(this_object());
    command("wear boots");
    new(ARM"dscalegloves.c")->move(this_object());
    command("wear gloves");
}

