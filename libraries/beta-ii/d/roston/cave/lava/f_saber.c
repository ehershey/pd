#include <std.h>
inherit WEAPON;

create() {
::create();
    set_id(({"saber","lava saber"}));
    set_name("lava Saber");
    set_short("%^BOLD%^%^RED%^L%^RESET%^%^RED%^a%^BOLD%^%^RED%^v"
              "%^RESET%^%^RED%^a %^BOLD%^%^RED%^S%^RESET%^%^RED%^a"
              "%^BOLD%^%^RED%^b%^RESET%^%^RED%^e%^BOLD%^%^RED%^r");
    set_long( "%^RED%^ This saber is one of a kind, that could only "
              "be found in the firey deeps..");
    set_mass(15);
    set_curr_value("gold", 58);
    set_wc(11);

    set_type("blade");
    set_hands(1);
}                    
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}     
