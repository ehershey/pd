#include <std.h>
#include <corinthor.h>

inherit MONSTER;

void create() {
   ::create();
        set_name("elven lady");
        set_id( ({"elf", "lady", "elven lady"}) );
        set_short("Elven lady");
        set_long("The lady of this home, she has a slight build and sun golden hair.");
        set_race("elf");
        set_gender("female");
        set_body_type("elf");
        set_level(random(5)+5);
        new(ELFARMOUR"ring.c")->move(this_object());
           command("wear ring");
}
