#include <std.h>
#include <aziraphale.h>
inherit MONSTER;

void create() {
   ::create();
	set_name("Kra'toan hunter");
	set_id( ({"monster", "hunter", "kra'toan"}) );
	set_heart_beat(1);

	set_short("a Kra'toan hunter");
	set_long("This appears to be hunter of the Kra'toan, a race of lizardmen that populate these forests but do not seem to have any central village.");
	set_race("Kra'toan");
	if (random(10) > 5)
	   set_gender("female");
	else
	   set_gender("male");
	set_body_type("human");
	set_level(43+random(3));
	set_alignment(100);
	new(KEEPWEAPON"zforest/spear.c")->move(this_object());
	command("wield spear");
        set_emotes(5, ({"The hunter scans the forest for likely prey.", "The hunter eyes you warily."}),0);
}
