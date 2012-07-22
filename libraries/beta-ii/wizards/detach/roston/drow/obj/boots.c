#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Boots");
    set_short("%^BOLD%^%^BLACK%^C%^RED%^l%^BLACK%^a%^RED%^w "
      "%^BLACK%^B%^RED%^o%^BLACK%^o%^RED%^t%^BLACK%^s%^RESET%^");
    set_long("These boots were formed from the one fo the claws "
      "of the Great Fire Dragon.");
    set_id( ({ "boots" , "claw boots" }) );
    set_ac(15);
    set_wear("%^ORANGE%^Your feet seem to sink into the ground.");
    set_remove("%^ORANGE%^Your Feet seem to rise.");
    set_mass(17);
    set_value(41);
    set_type("boots");
    set_limbs( ({ "right foot","left foot" }) );
}                  
int query_auto_load()
{
    if (wizardp(this_player())) return 1;
    return 1;
}                   