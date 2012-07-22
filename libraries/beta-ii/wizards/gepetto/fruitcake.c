//Gepetto

#include <gepetto.h>
#include <std.h>
inherit WEAPON;

void create() {
    ::create();
    set_hit((:this_object(), "weapon_hit":));
    set_name("Uncle Gepetto's holiday fruitcake");
    set_short("Uncle Gepetto's holiday fruitcake");
    set_long("Bleh, another damn fruitcake from that cheap Gepetto. Maybe
             you can club someone with it.");
    set_id(({"cake", "fruitcake"}));
    set_mass(25);
    set_value(0);
    set_type("blunt");
    set_hands(1);
    set_wc(5);
    set_ac(1);

}
int weapon_hit()
{
    int res;
    object atk;
    atk = (object)environment()->query_current_attacker();
    if(random(102) > 70) {
write ("%^BOLD%^%^GREEN%^%^Uncle Gepetto's%^%^RESET%^ %^BOLD%^%^RED%^%^holiday fruitcake%^%^RESET%^ %^BOLD%^%^CYAN%^%^weighs on your opponent like a ton of%^%^RESET%^ %^BOLD%^%^RED%^%^B%^%^RESET%^%^BOLD%^%^GREEN%^%^R%^%^RESET%^%^BOLD%^%^RED%^%^I%^%^RESET%^%^BOLD%^%^GREEN%^%^C%^%^RESET%^%^BOLD%^%^RED%^%^K%^%^RESET%^%^BOLD%^%^GREEN%^%^S%^%^RESET%^ %^BOLD%^%^RED%^%^!%^%^RESET%^ %^BOLD%^%^GREEN%^%^!%^%^RESET%^ ");
        say((string)this_player()->query_cap_name()+
"'s %^BOLD%^%^GREEN%^%^Uncle Gepetto's%^%^RESET%^ %^BOLD%^%^RED%^%^holiday fruitcake%^%^RESET%^ %^BOLD%^%^CYAN%^%^weighs on their opponent like a ton of%^%^RESET%^   %^BOLD%^%^RED%^%^B%^%^RESET%^%^BOLD%^%^GREEN%^%^R%^%^RESET%^%^BOLD%^%^RED%^%^I%^%^RESET%^%^BOLD%^%^GREEN%^%^C%^%^RESET%^%^BOLD%^%^RED%^%^K%^%^RESET%^%^BOLD%^%^GREEN%^%^S%^%^RESET%^ %^%^BOLD%^%^RED%^%^!%^%^RESET%^ %^BOLD%^%^GREEN%^%^!%^%^RESET%^ ");
res=(50+random(50)-random(50));
        return res;
        return 0;
    }
}
