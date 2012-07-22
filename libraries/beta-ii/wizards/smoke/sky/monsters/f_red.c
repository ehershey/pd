#include <std.h>
#include <cp.h>
inherit MONSTER;

create() {
         ::create();
         set_name("red dragon");
         set_id(({ "dragon", "red dragon" }));
         set_short("%^BOLD%^%^RED%^red dragon%^RED%^");
         set_long("The enormous %^BOLD%^%^RED%^red dragon%^RESET%^ "
                 "looks like she's been disturbed. Her scales are "
                 "the color of fire. She looks extremely unfriendly "
		 "and her roar is deafening.");
         set_race("dragon");
         set_class("dragon");
         set_subclass("red");
         set_body_type("dragon");
         set("aggressive", 75);
         set_stats("strength", 220);
         set_gender("female");
         set_level(78);
set_spell_chance(25);
         set_spells(({"breathe", "rage", "flameclaw"}));
    new(ARM"rring.c")->move(this_object());
    command("wear ring");

}
