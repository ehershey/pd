#include <std.h>
#include <helgrath.h>

inherit "/std/vendor";

create() {
    ::create();
    set_property("no bump", 1);
    set_name("Olaf");
    set_id( ({ "Olaf", "vendor", "olaf" }) );
    set_type(({"armour"}));
    set_short("Olaf, the armourer");
    set("aggressive", 0);
    set_level(30);
    set_long("This towering man boasts bulging blood-vessels on behemoth-sized limbs.\n");
    set_gender("male");
    set_alignment(122);
    set_storage_room(ROOMS"storage_armour.c");
    set("race", "human");
    add_money("gold", random(200));
    set_body_type("human");
    set_class("fighter");
    set_subclass("warrior");
    set_spell_chance(40);
    set_spells( ({"choke"}) );
    set_currency("gold");
}
