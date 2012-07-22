#include <std.h>
#include <cp.h>
inherit MONSTER;

create() {
         ::create();
         set_name("dragon slayer");
         set_id(({ "slayer", "dragon slayer" }));
         set_short("%^BOLD%^%^BLACK%^Dragon slayer%^RESET%^");
         set_long("This is the famed Dragon slayer. He makes a living "
                 "off of hunting dragons and selling bits of their "
		 "corpses. He shows no fear or mercy when hunting "
		 "and uses any tactics he can to bring them down.");
         set_race("raknid");
         set_class("fighter");
         set_subclass("warrior");
         set_body_type("artrell");
         set("aggressive", 75);
         set_stats("strength", 350);
         set_gender("male");
         set_level(155);
         set_spell_chance(40);
         set_spells(({"slash", "rush", "choke"}));
    new(WEAP"2haxe.c")->move(this_object());
    command("wield axe");
    new(WEAP"2haxe.c")->move(this_object());
    command("wield axe");
    new(WEAP"2haxe.c")->move(this_object());
    command("wield axe");
    new(WEAP"2haxe.c")->move(this_object());
    command("wield axe");
    new(ARM"charmask.c")->move(this_object());
    command("wear mask");
    new(ARM"ironhelm.c")->move(this_object());
    command("wear helm");
    new(ARM"spiderarmor.c")->move(this_object());
    command("wear armor");
}
