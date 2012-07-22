#include <std.h>
#include <helgrath.h>

inherit "/std/vendor";

create() {
    ::create();
    set_property("no bump", 1);
    set_name("Yorik");
    set_id( ({ "Yorik", "vendor", "yorik" }) );
    set_type(({"weapon"}));
    set_short("Yorik, the weaponsmith");
    set("aggressive", 0);
    set_level(30);
    set_long("This towering man boasts bulging blood-vessels on behemoth-sized appendages.\n");
    set_gender("male");
    set_alignment(122);
    set_storage_room(ROOMS"storage_weapons.c");
    set("race", "human");
    add_money("gold", random(200));
    set_body_type("human");
    set_currency("gold");
}
