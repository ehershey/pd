#include <std.h>
#include <helgrath.h>

inherit "/std/vendor";

create() {
    ::create();
    set_property("no bump", 1);
    set_name("Yaenel");
    set_id( ({ "Yaenel", "vendor", "yaenel", "mage" }) );
    set_type(({"armour"}));
    set_short("Yaenel, the mage");
    set("aggressive", 0);
    set_level(30);
    set_long("This towering man boasts bulging blood-vessels on behemoth-sized appendages.\n");
    set_gender("male");
    set_alignment(122);
    set_storage_room(ROOMS"storage_mage.c");
    set("race", "human");
    add_money("gold", random(200));
    set_body_type("human");
    set_class("mage");
    set_subclass("wizard");
    set_spell_chance(40);
    set_spells( ({"blast"}) );
    set_currency("gold");
}
