//Drackypoo.  020203
#include <std.h>
inherit "/std/deliv_object.c";
void create(){
::create();
  set_name("package");
  set_id(({ "package_weapon", "delivery package" }));
  set_short("a small package");
  set_long("A small package.  It reads:\n\nTO: Xor, the old");
  set_mass(24);
  set_value(1);
  set_devobtimeperiod(120);
  set_dev_value(45);
  set_dev_exp(75);
}
