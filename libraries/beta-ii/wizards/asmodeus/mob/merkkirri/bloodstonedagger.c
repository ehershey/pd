#include <std.h>
inherit WEAPON;

int weapon_hit();
create() {
::create();
set_id(({"dagger", "ivory dagger", "knife", "bloodstone", "bloodstone dagger"}));
set_name("dagger");
set_short("%^BOLD%^BLACK%^Bl%^RED%^oo%^YELLOW%^d%^RED%^sto%^BLACK%^ne %^RED%^Da%^BLACK%^g%^YELLOW%^g%^BLACK%^e%^RED%^r%^RESET%^");
set_long("An insideous looking dagger with a bloodstone set at the hilt.  The blade is nearly 10 inches in length and made of a red toned steel.");
set_weight(10);
set_value(500);
set_wc(16);
set_ac(0);
set_type("knife");
set_hands(1);
set("skill level", 150);
set_wield("%^BOLD%^RED%^You wield the bloodstone dagger.%^RESET%^");
set_unwield("%^BOLD%^RED%^You unwield the bloodstone dagger.%^RESET%^");
set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 85) {
write("%^BOLD%^RED%^The%^BOLD%^BLACK%^ bl%^RED%^oo%^YELLOW%^d%^RED%^sto%^BLACK%^ne%^RED%^ glistens as you stab "+ this_player()->query_current_attacker()->query_cap_name()+" deep in the chest!%^RESET%^");
say((string)"%^BOLD%^RED%^"+this_player()->query_cap_name()+" stabs "+this_player()->query_current_attacker()->query_cap_name()+" deeply in the chest!%^RESET%^");
result=(random(this_player()->query_level()))+(random(this_player()->query_skill("knife")/5));
return result;
}
}
int query_auto_load() {
if(this_player()->query_level() < 30) return 0;
return 1; }