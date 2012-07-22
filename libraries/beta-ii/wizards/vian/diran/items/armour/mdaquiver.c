#include <std.h>
#include <diran.h>
inherit "/std/obj/quiver.c";

int number=48;
void create() {
 ::create();
   set_name("quiver");
   set_short("a %^ORANGE%^brown%^RESET%^ and %^BOLD%^white%^RESET%^ striped quiver");
   set_long("This quiver is quite large and heavy.  It is striped with brown and white paint.  It currently contains "+number+" arrows.");
   set_size("dwarf");
set_material("cloth");
   set_id(({ "quiver", "striped quiver"}));
   set_mass(15);
   set_limbs(({"torso"}));
   set_type("quiver");
   set_value(20+random(20));
   set_ac(2);
   set_auto_load(20);
}