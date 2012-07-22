#include <std.h>
#include <corinthor.h>

inherit MONSTER;

void create() {
   ::create();
        set_name("guest");
        set_id( ({"elf", "guest"}) );
        set_short("a Guest");
        set_long("An elven guest in this home.");
        set_race("elf");
        if(random(2) == 1)
          set_gender("male");
        else
          set_gender("female");
        set_body_type("elf");
        set_level(random(5)+5);
        new(ELFARMOUR"blushirt.c")->move(this_object());
           command("wear shirt");
}
