#include <std.h>
inherit ARMOUR;

void create() {
::create();
set_name("glove");
set_long("The glove is made of a spiders silk that shimmers in the light.  You are amazed at how strong it feels.  This glove is fitted for the left hand.");
set_short("%^BOLD%^%^WHITE%^Sh%^RESET%^i%^BOLD%^%^WHITE%^m%^RESET%^me%^BOLD%^%^WHITE%^r%^RESET%^in%^BOLD%^%^WHITE%^g%^RESET%^BOLD%^%^GREEN%^ Glove%^RESET%^");
set_id(({"glove", "shimmering glove"}));
set_ac(2);
set_weight(4);
set_curr_value("gold",50);
set_type("gloves");
set_limbs(({"left hand"}));
}
int query_auto_load() {return 1; }
