#include <std.h>
#include <cp.h>
inherit MONSTER;

create() {
         ::create();
         set_name("dwarven priest");
         set_id(({ "dwarf", "priest", "dwarven priest" }));
         set_short("dwarven priest");
         set_long("The priest stands in front of the worship area "
                 "of the monestary. If anyone needs advice or a "
                 "prayer, they come see him. He's busy studying "
                 "a sacred book on the altar.");
         set_race("dwarf");
         set_class("clergy");
         set_subclass("monk");
         set_body_type("dwarf");
         set("aggressive", 0);
         set_gender("male");
         set_level(88);
    new(ARM"monksrobe.c")->move(this_object());
    command("wear robe");
    new(ARM"sandals.c")->move(this_object());
    command("wear sandals");
}
