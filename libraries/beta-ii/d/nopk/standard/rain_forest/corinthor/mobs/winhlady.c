#include <std.h>
#include <corinthor.h>

inherit MONSTER;

void create() {
   ::create();
        set_name("elven lady");
        set_id( ({"elf", "elven lady", "lady"}) );
        set_short("Elven lady");
        set_long("The lady of this house is an elf, but her partner is a human. An odd couple to stay in Corinthor.");
        set_race("elf");
        set_gender("female");
        set_body_type("elf");
        set_level(random(5)+5);
        new(ELFARMOUR"blushirt.c")->move(this_object());
           command("wear shirt");
        new(ELFARMOUR"ring.c")->move(this_object());
           command("wear ring");
}
