#include <std.h>

inherit OBJECT;

void create() {
  ::create();
    set_name("%^BOLD%^%^MAGENTA%^A %^BLUE%^co%^RED%^lo%^GREEN%^ur%^MAGENTA%^fu%^YELLOW%^l %^WHITE%^sign%^RESET%^");
    set_id( ({ "sign" }) );
    set_short("%^BOLD%^%^MAGENTA%^A %^BLUE%^co%^RED%^lo%^GREEN%^ur%^MAGENTA%^fu%^YELLOW%^l %^WHITE%^sign%^RESET%^");
    set_long("A colourful sign. There is something written on it.");
    set_mass(1);
    set_value(0);
    set_prevent_get("The sign is stuck to the ground.");
}

void init() {
  ::init();
    add_action("read", "read");
}

int read(string str) {
  if (!str)
    if (str!="sign") return 0;
    write("%^BOLD%^%^MAGENTA%^Here are the rules of the Egg Hunt.\n"
          " 1) No pking allowed during the event. Player who pked victim shall be removed from the event and all eggs taken.\n "
          "2) You may not auction, bury, sell or give away your eggs.\n "
          "3) Command stacking is illegal. No macros or triggers are allowed either.\n "
          "4) Try to have fun! :)/n");
    return 1;
}
