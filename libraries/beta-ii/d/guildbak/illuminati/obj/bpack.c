#include <std.h>

inherit PACK;

void create() {
   ::create();
     set_id( ({"pack", "mystic pack", "magic pack"}) );
     set_name("pack");
     set_short("%^BOLD%^MAGENTA%^a %^RESET%^MAGENTA%^M%^BOLD%^y%^RESET%^MAGENTA%^s%^BOLD%^t%^RESET%^MAGENTA%^i%^BOLD%^c %^RESET%^MAGENTA%^P%^BOLD%^a%^RESET%^MAGENTA%^c%^BOLD%^k%^RESET%^");
     set_weight(20);
     set_long("A most mysteriously mystical pack that has been meticulously made from a marvelous material.");
     set_curr_value("gold", 90);
     set_max_internal_encumbrance(1000);
     set_possible_to_close(1);
}

int query_auto_load() {
    if(this_player()->query_guild() == "illuminati")
      return 1;
}
