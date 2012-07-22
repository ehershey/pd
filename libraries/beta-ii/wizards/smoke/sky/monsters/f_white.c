#include <std.h>
#include <cp.h>
inherit MONSTER;

create() {
         ::create();
         set_name("white dragon");
         set_id(({ "dragon", "white dragon" }));
         set_short("%^BOLD%^%^WHITE%^white dragon%^RED%^");
         set_long("The enormous %^BOLD%^%^WHITE%^white dragon%^RESET%^ "
                 "is arched back on her two hind legs. Her tail "
                 "swishes behind her carelessly. A sense of holiness "
		 "comes from her somehow.");
         set_race("dragon");
         set_class("dragon");
         set_subclass("white");
         set_body_type("dragon");
         set("aggressive", 75);
         set_stats("wisdom", 180);
         set_gender("female");
         set_level(125);
	 set_money("gold" ,1450);
set_spell_chance(50);
         set_spells(({"breathe", "solarflare"}));
    new(ARM"wring.c")->move(this_object());
    command("wear ring");

}
