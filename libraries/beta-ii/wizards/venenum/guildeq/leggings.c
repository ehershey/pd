#include <std.h>
#include <venguilds.h>
inherit GUILDARM;

void create() {
    :: create();
    set_ac(4);
    set_mass(10);
    set_curr_value("gold", 90);
    set_type("leggings");
    set_limbs(({"right leg","left leg"}));
}
