
#include <std.h>
inherit WEAPON;

create() {
::create();
set_id(({"staff", "rib staff"}));
set_name("staff");
set_short("%^YELLOW%^R%^BLUE%^i%^YELLOW%^b "
    "%^BLUE%^S%^YELLOW%^t%^BLUE%^a%^YELLOW%^f%^BLUE%^f%^RESET%^");
set_long("%^BOLD%^%^WHITE%^This staff was formed from the a rib bone "
          "on the great Fire Dragon.");
set_weight(17);
set_value(80);
set_wc(13);
set_ac(3);
set_type("blunt");
set_hands(2);
set_wield("%^BOLD%^%^BLUE%^You grip the bone tightly.");
set_unwield("%^ORANGE%^The Bone slips out of your hands.");
}

int query_auto_load()
{                                  
 if (wizardp(this_player())) return 1;
 return 1;
}
