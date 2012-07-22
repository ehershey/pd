#include <std.h>
#include <diran.h>
inherit "/std/obj/quiver.c";

int number=48;
void create() {
 ::create();
   set_name("quiver");
   set_short("a %^BOLD%^%^BLACK%^black leather%^RESET%^ quiver");
   set_long("This quiver is quite large and heavy.  It is made entirely of black leather.  It currently contains "+number+" arrows.");
   set_size("dwarf");
set_material("cloth");
   set_id(({ "quiver", "leather quiver"}));
   set_mass(15);
   set_limbs(({"torso"}));
   set_type("quiver");
   set_value(20+random(20));
   set_ac(2);
   set_auto_load(20);
}