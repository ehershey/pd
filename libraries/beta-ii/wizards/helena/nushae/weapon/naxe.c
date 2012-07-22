#include <std.h>

inherit WEAPON;

void create() {
  ::create();
    set_name("axe");
    set_id(({ "axe" }));
    set_short("%^CYAN%^Nu%^MAGENTA%^Sh%^CYAN%^ae%^RESET%^ %^ORANGE%^Axe%^RESET%^");
    set_long("An axe native to %^CYAN%^Nu%^MAGENTA%^Sh%^CYAN%^ae%^RESET%^, made from %^CYAN%^Iron %^RESET%^and %^MAGENTA%^Coral%^RESET%^ direct from their mines.");
    set_type("axe");
    set_wc(5);
    set_weight(15);
    set_curr_value("gold", 50-random(15));
}

int query_auto_load(){
    if (this_player()->query_level() > 15) return 1;
    return 0;
}