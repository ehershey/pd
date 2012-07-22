#include <std.h>
#include <corinthor.h>
inherit MONSTER;

void create() {
   ::create();
        set_name("royal guard");
        set_id( ({"elf", "guard", "royal guard", "monster", "royalguard"}) );
        set_heart_beat(1);
        set_short("Royal Guard");
        set_long("The royal guards are stationed throughout the palace, keeping the many servants and guests safe.");
        set_race("elf");
        if(random(2) == 1) set_gender("male");
        else set_gender("female");
        set_body_type("elf");
        set_level(12);
        new(ELFWEAPON"scimitar.c")->move(this_object());
           command("wield scimitar");
        new(ELFARMOUR"elfchainmail.c")->move(this_object());
           command("wear chainmail");
}
