//Drackypoo.  020203
#include <std.h>
inherit "/std/deliv_object.c";
void create(){
::create();
  set_name("package");
  set_id(({ "package_apu", "delivery package" }));
  set_short("a small package");
  set_long("A small package.  It reads:\n\nTO: Apu, the hindu clerk\n"
"WARNING: PERISHABLE, DELIVER QUICKLY");
  set_mass(9);
  set_value(1);
  set_devobtimeperiod(40);
  set_dev_value(60);
  set_dev_exp(100);
}
