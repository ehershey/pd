#include <std.h>
inherit WEAPON;

create() {
::create();
    set_id(({"lance","lava lance"}));
    set_name("lava Lance");
    set_short("%^BOLD%^%^RED%^L%^RESET%^%^RED%^a%^BOLD%^%^RED%^v"
              "%^RESET%^%^RED%^a %^BOLD%^%^RED%^L%^RESET%^%^RED%^a"
              "%^BOLD%^%^RED%^n%^RESET%^%^RED%^c%^BOLD%^%^RED%^e");
    set_long( "%^RED%^ This lance is one of a kind, that could only "
              "be found in the firey deeps..");
    set_mass(50);
    set_value(400+random(40));
    set_wc(10);
    set_ac(5);
    set_type("blade");
    set_hands(1);
}              
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}     
