#include <std.h>
inherit MONSTER;

void create() {
::create();
    
set_name("death dragon");
set_short("death dragon");
set_long("SET THIS WITH COLOR");
    set_id(({"dragon","death dragon"}));
    set_level(75);
    set("aggressive", 25);
    set_race("dragon");
    set_class("dragon");
    set_subclass("black");
    set_spell_chance(35);
    set_spells(({"claw"}));
    set_body_type("dragon");
    set_gender("male");
    set_exp(150000);
}
