#include <mjungle.h>
#include <std.h>
inherit OBJECT;

void create() {
::create();
set_short("a %^RESET%^RED%^blood%^RESET%^BOLD%^BLACK%^ altar%^RESET%^");
set_name("altar");
set_id(({"altar", "blood altar"}));
set_long("An altar made of black adamantite and filled with the blood of several sacrifices.");
set_weight(100000);
set_value(0);
}
