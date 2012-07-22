#include <std.h>
inherit WEAPON;

void create() {
::create();
set_id(({"sword", "blade"}));
set_name("sword");
set_short("%^RESET%^BLUE%^S%^GREEN%^w%^BLUE%^or%^BOLD%^BLACK%^d%^RESET%^BLUE%^ of C%^GREEN%^h%^BLUE%^ao%^BOLD%^BLACK%^s%^RESET%^");
set_long("%^GREEN%^The Sword of Chaos is shaped much like an enlongated butcher knife with a silver-blue blade.  It's hilt is made of pure platinum and is adorned by two sapphires and an emerald.  A black star seems to float lazily inside the large emerald.%^RESET%^");
set_curr_value("gold",100);
set_weight(17);
set_wc(10);
set_ac(1);
set_type("blade");
}
