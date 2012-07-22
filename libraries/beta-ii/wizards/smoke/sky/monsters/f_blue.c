#include <std.h>
#include <cp.h>
inherit MONSTER;

create() {
         ::create();
         set_name("blue dragon");
         set_id(({ "dragon", "blue dragon" }));
         set_short("%^BOLD%^%^BLUE%^blue dragon%^RED%^");
         set_long("The enormous %^BOLD%^%^BLUE%^blue dragon%^RESET%^ "
                 "is arched back on her two hind legs. Her tail "
                 "swishes behind her carelessly. A peaceful gleam "
		 "can be seen in her eye.");
         set_race("dragon");
         set_class("dragon");
         set_subclass("blue");
         set_body_type("dragon");
         set("aggressive", 75);
         set_stats("wisdom", 200);
         set_gender("female");
         set_level(125);
	 set_money("gold" ,1450);
set_spell_chance(50);
         set_spells(({"breathe", "dragonfury"}));
    new(ARM"blring.c")->move(this_object());
    command("wear ring");

}
