#include <std.h>
#include <corinthor.h>
inherit MONSTER;

void create() {
   ::create();
        set_name("elven noble");
        set_id( ({"elf", "noble", "elven noble", "monster"}) );
        set_heart_beat(1);
        set_short("elven noble");
        set_long("One of the many elven nobles through the land, most likely here on official business from somewhere outside of Corinthor.");
        set_race("elf");
        if(random(2) == 1) set_gender("male");
        else set_gender("female");
        set_body_type("elf");
        set_level(11);
        new(ELFARMOUR"noblepants.c")->move(this_object());
           command("wear pants");
        new(ELFARMOUR"nobletunic.c")->move(this_object());
           command("wear tunic");
}
