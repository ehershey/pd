#include <std.h>														
inherit ARMOUR;															
void create() {	
   ::create();	
	set_name("Gold Necklace");
	set_id( ({ "necklace" }) );
	set_short("Gold necklace");
	set_long("This is a very old necklace, it has been passed down from generation to generation to insure that it is kept safe");
	set_ac(1);
	set_curr_value("gold", 40);
	set_limbs( ({ "head" }) );
	set_weight(2);
	set_type("necklace");
}
