#include <std.h>
#include <cp.h>
inherit MONSTER;

create() {
         ::create();
         set_name("dwarven thief");
         set_id(({ "dwarf", "thief", "dwarven thief" }));
         set_short("%^");
         set_long("The thief is dressed in all black, holding a knife "
                 "up his sleeve.");
         set_race("dwarf");
         set_class("rogue");
         set_subclass("thief");
         set_body_type("dwarf");
         set("aggressive", 0);
         set_gender("male");
         set_level(80);
set_spell_chance(70);
         set_spells(({"stab"}));
    new(ARM"f_cloak.c")->move(this_object());
    command("wear cloak");
    new(WEAP"j_dagger.c")->move(this_object());
    command("wield dagger");
}
