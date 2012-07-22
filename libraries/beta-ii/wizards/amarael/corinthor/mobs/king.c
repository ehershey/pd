#include <std.h>
#include <corinthor.h>
inherit MONSTER;

void create() {
   ::create();
        set_name("Leseld");
        set_id( ({"leseld", "king", "monster"}) );
        set_heart_beat(1);
        set_short("%^BOLD%^GREEN%^Leseld, King of Corinthor.");
        set_long("Leseld is the king of Corinthor, and lord of all the forest. He rules the land fairly with the aid of his council. The weapon he wields signifies him as king.");
        set_race("elf");
        set_gender("male");
        set_body_type("elf");
        set_level(15);
        set_alignment(10);
        new(ELFWEAPON"moonblade.c")->move(this_object());
           command("wield moonblade");
        new(ELFARMOUR"platemail.c")->move(this_object());
	   command("wear platemail");
	new(ELFARMOUR"royalcrown.c")->move(this_object());
	   command("wear crown");
}
