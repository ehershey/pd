#include <mjungle.h>
#include <std.h>
inherit OBJECT;

void create() {
::create();
    set_name("portal");
set_short("A%^GREEN%^ glowing portal%^RESET%^");
    set_long("%^GREEN%^A glowing portal.");
    set_id(({"portal", "glowing portal"}));
    set_mass(100000);
    set_value(1);
}
