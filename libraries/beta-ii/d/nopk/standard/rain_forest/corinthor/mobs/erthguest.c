#include <std.h>
#include <corinthor.h>

inherit MONSTER;

void create() {
   ::create();
        set_name("guest");
        set_id( ({"elf", "guest"}) );
        set_short("Elven guest");
        set_long("An elven guest in this home of the Earth Tree. Probably not expecting this strange interruption.");
        set_race("elf");
        if(random(2) == 1)
          set_gender("male");
        else
          set_gender("female");
        set_body_type("elf");
        set_level(random(5)+5);
        if(random(2) == 1)
          new(ELFARMOUR"blushirt.c")->move(this_object());
        else
          new(ELFARMOUR"grnshirt.c")->move(this_object());
           command("wear shirt");
}
