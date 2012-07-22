#include <std.h>
#include <cp.h>
inherit MONSTER;

create() {
         ::create();
         set_name("black dragon");
         set_id(({ "dragon", "black dragon" }));
         set_short("%^BOLD%^%^BLACK%^black dragon%^RED%^");
         set_long("The enormous %^BOLD%^%^BLACK%^black dragon%^RESET%^ "
                 "looks like she's been disturbed. Her scales are "
                 "jet black and look thick. She stands on her hind "
		 "legs awaiting some unfriendly nemesis.");
         set_race("dragon");
         set_class("dragon");
         set_subclass("black");
         set_body_type("dragon");
         set("aggressive", 75);
         set_stats("intelligence", 180);
         set_gender("female");
         set_level(125);
	 set_money("gold" ,1500);
set_spell_chance(40);
         set_spells(({"breathe", "chainlightning"}));
    new(ARM"bring.c")->move(this_object());
    command("wear ring");

}
