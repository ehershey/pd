#include <std.h>
#include <cp.h>
inherit MONSTER;

create() {
         ::create();
         set_name("dwarven villager");
         set_id(({ "dwarf", "villager", "dwarven villager" }));
         set_short("dwarven villager");
         set_long("The villager doesn't have a whole lot going on. "
                 "He's sipping on his ale and watching other villagers "
		 "go about their business.");
         set_race("dwarf");
         set_class("fighter");
         set_subclass("warrior");
         set_body_type("dwarf");
         set("aggressive", 75);
         set_gender("male");
         set_level(77);
    new(WEAP"m_axe.c")->move(this_object());
    command("wield axe");
    new(ARM"l_armour.c")->move(this_object());
    command("wear armour");
set_emotes(10, ({"The dwarven villager clears his throat.",
	"The dwarven villager takes a swig of some ale.",
	"The dwarven villager cracks his knuckles."}), 0);
}
