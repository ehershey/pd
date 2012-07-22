#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("robes");
    set_short("%^BOLD%^%^BLACK%^Bl%^WHITE%^ac%^BLACK%^k Ro%^WHITE%^be%^BLACK%^s%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^These robes seemed to be formed of a deep black mist.");
    set_id( ({ "robes" , "black robes" }) );
    set_ac(2);
    set_mass(11);
  set_curr_value("gold",80+random(40));
    set_type("robes");
    set_limbs( ({ "head","torso","right arm","left arm","left leg","right leg"
}) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
