#include <std.h>
#include <cp.h>
inherit MONSTER;

create() {
         ::create();
         set_name("dwarven prophet");
         set_id(({ "dwarf", "prophet", "dwarven prophet" }));
         set_short("dwarven prophet");
         set_long("The prophet studies history books and religous "
                 "materials. He is very wise and in touch with his "
                 "spirituallity. He thinks he can tell the future.");
         set_race("dwarf");
         set_class("clergy");
         set_subclass("monk");
         set_body_type("dwarf");
         set("aggressive", 50);
         set_gender("male");
         set_level(84);
    new(ARM"monksrobe.c")->move(this_object());
    command("wear robe");
    new(ARM"sandals.c")->move(this_object());
    command("wear sandals");
}
