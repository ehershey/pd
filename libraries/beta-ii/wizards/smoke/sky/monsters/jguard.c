#include <std.h>
#include <cp.h>
inherit MONSTER;

create() {
         ::create();
         set_name("dwarven prison guard");
         set_id(({ "dwarf", "prison guard", "guard", "dwarven prison guard" }));
         set_short("dwarven prison guard");
         set_long("This dwarf stands guard, making sure no "
                 "prisoners escape or harm each other too badly. "
		 "a very long, bushy beard. He stands here starinag "
		 "He looks as though he's going to fall asleep. ");
         set_race("dwarf");
         set_class("fighter");
         set_subclass("warrior");
         set_body_type("dwarf");
	 set_skill("blade", 500);
         set("aggressive", 75);
         set_gender("male");
         set_level(82);
    new(WEAP"riot.c")->move(this_object());
    command("wield blade");
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
