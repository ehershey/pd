#include <std.h>
#include "ether.h"
inherit ARMOUR;
void create() {
    ::create();
    set_name("wingmail");
    set("id", ({ "wings", "holy wings" }) );
    set("short", "%^BOLD%^%^BLUE%^F%^CYAN%^r%^WHITE%^o"
      "%^YELLOW%^s%^WHITE%^t%^CYAN%^e%^BLUE%^d %^BLUE%^"
      "W%^CYAN%^i%^WHITE%^n%^YELLOW%^gm%^WHITE%^a%^CYAN%^"
      "i%^BLUE%^l%^RESET%^");
    set("long", "%^CYAN%^This is a set of Holy Wingmail "
      "designed specifically for Angels by a very "
      "powerful Ice Sorceror. They help their wearer "
      "keep cool during a heated battle.%^RESET%^");
    set_ac(1);
    set_limbs( ({ "left wing", "right wing" }) );
    set_weight(1);
    set_curr_value("gold", 40);
    set_type("wing armour");
}
