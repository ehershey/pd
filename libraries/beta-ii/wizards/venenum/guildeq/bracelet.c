#include <std.h>
#include <venguilds.h>
inherit GUILDARM;

void create() {
    :: create();
    set_ac(2);
    set_mass(1);
    set_curr_value("gold", 190);
    set_type("bracelet");
}
