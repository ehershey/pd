#include <std.h>
#include <corinthor.h>
inherit MONSTER;

void create() {
   ::create();
        set_name("elven knight");
        set_id( ({"elf", "knight", "elven knight", "monster"}) );
        set_heart_beat(1);
        set_short("Elven Knight");
        set_long("The Knight's are here to make sure that the palace remains secure from intruders. They are equipped with good weapons and armour to fight off agressors.");
        set_race("elf");
        if(random(2) == 1) set_gender("male");
        else set_gender("female");
        set_body_type("elf");
        set_level(13);
	new(ELFWEAPON"runesword.c")->move(this_object());
           command("wield runesword");
	new(ELFARMOUR"knightshield.c")->move(this_object());
	   command("wear shield");
        new(ELFARMOUR"elfchainmail.c")->move(this_object());
	   command("wear chainmail");
}
