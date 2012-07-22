#include <std.h>
inherit WEAPON;

create() {
::create();
set_id(({"tooth", "dragon tooth","sword"}));
set_name("tooth");
set_short("%^BOLD%^%^WHITE%^D%^RESET%^%^GREEN%^r%^BOLD%^%^WHITE%^a"
    "%^RESET%^%^GREEN%^g%^BOLD%^%^WHITE%^o%^RESET%^%^GREEN%^n "
    "%^BOLD%^%^WHITE%^T%^RESET%^%^GREEN%^o%^BOLD%^%^WHITE%^o"
    "%^RESET%^%^GREEN%^t%^BOLD%^%^WHITE%^h%^RESET%^");
set_long("%^BOLD%^%^WHITE%^This is a giant tooth from the mouth "
         "of the great Fire Dragon.");
set_weight(24);
    set_curr_value("gold", 40);
set_wc(8);
set_type("blade");
set_hands(1);
set_wield("%^BOLD%^%^RED%^You cut Your hands on the sharp tooth.");
set_unwield("%^GREEN%^The Pain leaves your hands.");
}

int query_auto_load()
{                                  
 if (wizardp(this_player())) return 1;
 if(this_player()->query_level() < 21) return 0;
 return 1;
}

