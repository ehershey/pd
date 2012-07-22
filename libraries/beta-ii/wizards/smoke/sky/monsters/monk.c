#include <std.h>
#include <cp.h>
inherit MONSTER;

create() {
         ::create();
         set_name("dwarven monk");
         set_id(({ "dwarf", "monk", "dwarven monk" }));
         set_short("dwarven monk");
         set_long("The monk has a long, scruffy brown beard that "
                 "almost reaches to the floor. He is wearing a colorful "
		 "robe with the hood draped over his eyes. His head "
		 "is pointed to the floor, probably indicating that "
		 "he's in the middle of prayer.");
         set_race("dwarf");
         set_class("clergy");
         set_subclass("monk");
         set_body_type("dwarf");
         set("aggressive", 0);
         set_gender("male");
         set_level(80);
    new(ARM"monksrobe.c")->move(this_object());
    command("wear robe");
}
