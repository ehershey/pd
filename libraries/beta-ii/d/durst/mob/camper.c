#include <std.h>
#include <durst.h>
inherit MONSTER;
void create() {
   ::create();
	set_name("camper");
	set_id( ({ "traveller", "human" }) );
	set_short("Sleepy traveller");
	set_long("The tired traveller stares into the fire, completely unaware of everything going on around him.");
	set_level(7);
	set_body_type("human");
	set_alignment(1);
	set_race("human");
	set_gender("male");
	set("aggressive", 8);
	new(ARM"hide_jerkin.c")->move(this_object());
	new(WEP"old_mace.c")->move(this_object());
	force_me("wear jerkin");
	force_me("wield mace" );
}