#include <std.h>
#include <diran.h>

inherit ARMOUR;
void create() {
 ::create();
   set_name("white trousers");
   set_short("a pair of %^BOLD%^%^WHITE%^white%^RESET%^ trousers");
   set_long("Made of a thick and rugged material, these trousers look as if they will protect from cold as well as wetness.");
   set_size("dwarf");
set_material("cloth");
   set_id(({ "trousers", "pants", "white pants", "white trousers"}));
   set_mass(5);
   set_limbs(({"right leg", "left leg"}));
   set_type("leggings");
   set_value(20+random(20));
   set_ac(3);
set_auto_load(20);
}

