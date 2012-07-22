#include <std.h>
#include <corinthor.h>

inherit MONSTER;

void create() {
   ::create();
        set_name("elven lord");
        set_id( ({"elf", "lord", "elven lord"}) );
        set_short("Elven lord");
        set_long("The lord of an elven home, by the surprised look on his face he wasn't expecting this intrusion.");
        set_race("elf");
        set_gender("male");
        set_body_type("elf");
        set_level(random(5)+5);
        new(ELFARMOUR"ring.c")->move(this_object());
           command("wear ring");
        new(ELFARMOUR"blkshirt.c")->move(this_object());
           command("wear shirt");
}
