#include <std.h>
#include <venguilds.h>
inherit GUILDARM;

void create() {
    :: create();
    set_ac(2);
    set_mass(10);
    set_curr_value("gold", 130);
    set_type("vest");
    set_limbs(({"torso"}));
}
