#include <std.h>
inherit WEAPON;

void create() {
  ::create();

  set_id(({"staff","God staff"}));
  set_name("God staff");
  set_short("%^BLUE%^G%^RESET%^%^YELLOW%^o%^RESET%^%^BLUE%^d%^RESET%^ "
            "%^YELLOW%^S%^RESET%^%^BLUE%^t%^RESET%^%^YELLOW%^a%^RESET%^"
            "%^BLUE%^f%^RESET%^%^YELLOW%^f%^RESET%^");
set_long("%^YELLOW%^A%^RESET%^ %^BLUE%^H%^RESET%^"
         "%^YELLOW%^o%^RESET%^BLUE%^l%^RESET%^YELLOW%^y%^RESET%^ "
         "%^BLUE%^Staff.%^RESET%^");
  set_mass(12);
    set_curr_value("gold", 40);
  set_wc(6);

  set_type("blunt");
  set_hands(1);
}                                 

int query_auto_load()  { 
  if(this_player()->query_level() < 20) return 0;
  return 1; }
