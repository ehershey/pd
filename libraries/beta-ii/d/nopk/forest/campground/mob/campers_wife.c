#include <std.h>
#include <durst.h>
inherit MONSTER;
void create() {
   ::create();
	set_name("Wife");
	set_id( ({ "traveller", "wife", "human" }) );
	set_short("Traveller's wife");
        set_long("This is one of the wives of the travellers here.  She looks very weathered and grumpy.");
	set_level(9);
	set_body_type("human");
	set_race("human");
	set_alignment(1);
	set_gender("female");
	set("aggressive", 12);
	new(ARM"hide_jerkin.c")->move(this_object());
	new(WEP"old_mace.c")->move(this_object());
	force_me("wear jerkin");
	force_me("wield mace" );
}
