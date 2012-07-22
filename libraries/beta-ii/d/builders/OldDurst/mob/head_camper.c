#include <std.h>
#include <durst.h>
inherit MONSTER;
void create() {
   ::create();
	set_name("Head traveller");
	set_id( ({ "traveller", "human" }) );
	set_short("Head traveller");
        set_long("This guy looks to be the head of the camp and appears to know much about the art of camping.");
	set_level(10);
	set_body_type("human");
        set_alignment(300);
	set_race("human");
	set_gender("male");
	set("aggressive", 8);
	new(ARM"hide_jerkin.c")->move(this_object());
	
	new(WEP"old_mace.c")->move(this_object());
	
	force_me("wear jerkin");
	force_me("wield mace" );
}
