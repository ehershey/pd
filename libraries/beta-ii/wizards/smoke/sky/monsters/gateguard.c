#include <std.h>
#include <cp.h>
inherit MONSTER;

create() {
         ::create();
         set_name("dwarven gate guard");
         set_id(({ "dwarf", "gate guard", "dwarf guard", "guard", "dwarven gate guard", "dwarven guard" }));
         set_short("dwarven gate guard");
         set_long("This dwarf stands guard at the gate of Steel "
                 "Hammer Village. He is short and stout with "
		 "a very long, bushy beard. He stands here staring "
		 "into thin air dreaming about the finer things in "
		 "life.. like his ale.");
         set_race("dwarf");
         set_class("fighter");
         set_subclass("warrior");
         set_body_type("dwarf");
         set("aggressive", 75);
         set_gender("male");
         set_level(85);
    new(WEAP"c_sword.c")->move(this_object());
    command("wield sword");
    new(WEAP"c_sword.c")->move(this_object());
    command("wield sword");
    new(ARM"c_belt.c")->move(this_object());
    command("wear belt");
    new(ARM"f_cloak.c")->move(this_object());
    command("wear cloak");
    new(ARM"l_armour.c")->move(this_object());
    command("wear armour");
    new(ARM"l_bracers.c")->move(this_object());
    command("wear bracers");
    new(ARM"l_gloves.c")->move(this_object());
    command("wear gloves");
    new(ARM"l_boots.c")->move(this_object());
    command("wear boots");
    new(ARM"l_helm.c")->move(this_object());
    command("wear helm");
    new(ARM"l_pants.c")->move(this_object());
    command("wear pants");
}
