#include <mjungle.h>
#include <std.h>
inherit OBJECT;

void create() {
 ::create();
set_id(({"gatekeep"}));
set_name("gatekeep");
set_long("");
set_short("%^YELLOW%^BOLD%^A Solid Gold Gatekeep%^RESET%^");
set_weight(100000000);
   set("value", 90000);
}

int get() { return 0; }
