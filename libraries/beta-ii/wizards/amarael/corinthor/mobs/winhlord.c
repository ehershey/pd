#include <std.h>
#include <corinthor.h>

inherit MONSTER;

void create() {
   ::create();
        set_name("human lord");
        set_id( ({"human", "human lord", "lord"}) );
        set_short("Human lord");
        set_long("The lord of this home is not an elf, but rather a human. That would explain for the strange decorations around the place.");
        set_race("human");
        set_gender("male");
        set_body_type("human");
        set_level(random(5)+5);
        new(ELFARMOUR"grnshirt.c")->move(this_object());
           command("wear shirt");
        new(ELFARMOUR"ring.c")->move(this_object());
           command("wear ring");
}
