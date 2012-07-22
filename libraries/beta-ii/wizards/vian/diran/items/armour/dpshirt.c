#include <std.h>
#include <diran.h>

inherit ARMOUR;
void create() {
 ::create();
   set_name("shirt");
   set_short("a %^BOLD%^%^BLUE%^blue%^RESET%^ cotton shirt");
   set_long("This shirt is made of blue cotton.  It has charred edges and a few smoke-stains.");
   set_size("dwarf");
set_material("cloth");
   set_id(({ "shirt", "blue shirt", "cotton shirt", "blue cotton shirt"}));
   set_mass(5);
   set_limbs(({"right arm", "torso", "left arm"}));
   set_type("tunic");
   set_value(30);
   set_ac(3);
set_auto_load(20);
}
