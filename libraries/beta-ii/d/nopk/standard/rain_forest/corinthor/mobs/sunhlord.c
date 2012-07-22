#include <std.h>
#include <corinthor.h>

inherit MONSTER;

void create() {
   ::create();
        set_name("elven lord");
        set_id( ({"elf", "lord", "elven lord"}) );
        set_short("Elven lord");
        set_long("The lord of this home, he is strong and muscular for an elf.");
        set_race("elf");
        set_gender("male");
        set_body_type("elf");
        set_level(random(5)+5);
        new(ELFARMOUR"ring.c")->move(this_object());
           command("wear ring");
}
