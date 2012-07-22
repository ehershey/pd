#include <std.h>
inherit WEAPON;
create() {
    ::create();
    set_id(({"knife","dark souls knife","darksouls knife"}));
    set_name("dark souls knife");
    set_short("%^BOLD%^%^BLACK%^D%^WHITE%^a%^BLACK%^r%^WHITE%^k "
      "%^BLACK%^S%^WHITE%^o%^BLACK%^u%^WHITE%^l%^BLACK%^s "
      "%^WHITE%^K%^BLACK%^n%^WHITE%^i%^BLACK%^f%^WHITE%^e"
      "%^RESET%^");
    set_long( "%^BOLD%^%^WHITE%^This Knife was formed from the "
      "Soul of a %^BLACK%^Ancient%^WHITE%^ warrior.");
    set_mass(9);
    set_curr_value("gold",random(40));
    set_wc(9);
    set_type("knife");
    set_hands(1);    
    set_wield("%^BOLD%^%^BLACK%^The Power of past souls fills you.");
    set_unwield("%^BOLD%^%^WHITE%^You feel the power of the souls leave "
      "you.");
}
int query_auto_load() { if (this_player()->query_level() > 30) return 1; }