#include <std.h>
#include <cp.h>
inherit VENDOR;

create() {
         ::create();
         set_name("dwarven tailor");
         set_id(({ "dwarf", "tailor", "dwarven tailor" }));
         set_short("A famed dwarven tailor");
         set_long("One of the few dwarves in Steel Hammer "
                 "Village that works at the armoury. She "
                 "is an excellent tailor and seamstress. "
                 "She has some of her most common merchandise "
		 "for sale.");
         set_race("dwarf");
         set_class("fighter");
         set_subclass("berserker");
         set_body_type("dwarf");
         set("aggressive", 0);
         set_gender("female");
         set_level(95);
set_currency("gold");
set_storage_room(ROOMS"armourstorage");
set_skill("bargaining", 200);
    new(ARM"apron2.c")->move(this_object());
    command("wear apron");
}
