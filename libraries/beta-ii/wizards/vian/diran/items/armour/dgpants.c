#include <std.h>
#include <diran.h>

inherit ARMOUR;
void create() {
 ::create();
   set_name("black pants");
   set_short("a pair of %^BOLD%^%^BLACK%^black%^RESET%^ pants");
   set_long("Made of a fairly thin fabric, these pants look as if they have been charred in spots.");
   set_size("dwarf");
set_material("cloth");
   set_id(({ "pants", "black pants"}));
   set_mass(5);
   set_limbs(({"right leg", "left leg"}));
   set_type("leggings");
   set_value(20+random(20));
   set_ac(3);
set_auto_load(20);
}
