#include <std.h>
#include <cp.h>
inherit MONSTER;

create() {
         ::create();
         set_name("ogre shaman");
         set_id(({ "shaman", "ogre", "ogre shaman" }));
         set_short("%^BOLD%^%^BLACK%^ogre shaman");
         set_long("This ogre is covered in tribal tattoos that "
                 "decorate his entire body. His body is sculpted "
                 "as though he were carved from stone. He is "
		 "wearing a mask, but evil red eyes stare through.");
         set_race("ogre");
         set_class("clergy");
         set_subclass("monk");
         set_body_type("ogre");
         set("aggressive", 60);
         set_stats("wisdom", 500);
         set_gender("male");
         set_level(90);
         set_spell_chance(40);
         set_spells(({"furystrike", "eagleclaw"}));
    new(ARM"vmask.c")->move(this_object());
    command("wear mask");
}
