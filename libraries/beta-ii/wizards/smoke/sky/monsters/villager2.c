#include <std.h>
#include <cp.h>
inherit MONSTER;

create() {
         ::create();
         set_name("dwarven villager");
         set_id(({ "dwarf", "villager", "dwarven villager" }));
         set_short("dwarven villager");
         set_long("The villager is just standing here. She stares "
                 "into space, daydreaming about who knows what. ");
         set_race("dwarf");
         set_class("fighter");
         set_subclass("warrior");
         set_body_type("dwarf");
         set("aggressive", 75);
         set_gender("female");
         set_level(76);
    new(WEAP"j_dagger.c")->move(this_object());
    command("wield dagger");
    new(ARM"l_armour.c")->move(this_object());
    command("wear armour");
set_emotes(10, ({"The dwarven villager looks you over.",
	"The dwarven villager mumbles something to herself."}), 0);
}
