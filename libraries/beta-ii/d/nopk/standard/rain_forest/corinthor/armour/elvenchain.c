#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
     set_name("chainmail");
     set_short("Elven Chainmail");
     set_long("This chainmail is a very shiny steel color. It looks very well made");
     set_id(({"armour", "chainmail"}));
     set_ac(4);
     set_mass(20);
     set_curr_value("gold", 40);
     set_type("chainmail");
     set_limbs(({"torso", "left arm", "right arm"}));
}
int query_auto_load() { return 1; }