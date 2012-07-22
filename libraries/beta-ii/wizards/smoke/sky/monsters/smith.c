
#include <std.h>
#include <cp.h>
inherit VENDOR;

create() {
         ::create();
         set_name("Grogg Stonebeard");
         set_id(({ "grogg stonebeard", "grogg", "blacksmith", "dwarf", "dwarven blacksmith" }));
         set_short("Grogg Stonebeard the dwarven blacksmith");
         set_long("Grogg hammers away on a weapon. He is always "
                 "hard at work on customized weapons. Soot is "
                 "smeared all over his sweaty face. A look of "
                 "concentration is studying the weapon he "
		 "is crafting.");
         set_race("dwarf");
         set_class("fighter");
         set_subclass("berserker");
         set_body_type("dwarf");
         set("aggressive", 0);
         set_gender("male");
         set_level(130);
set_currency("gold");
set_storage_room(ROOMS"smithstorage");
set_skill("bargaining", 200);
    new(WEAP"groggshammer.c")->move(this_object());
    command("wield hammer");
    new(ARM"apron.c")->move(this_object());
    command("wear apron");
}
