//Drackypoo.  020203
#include <std.h>
inherit "/std/deliv_object.c";
void create(){
::create();
  set_name("package");
  set_id(({ "package_tanner", "delivery package" }));
  set_short("a small package");
set_long("A small package.  It reads:\n\nTO: Garon, the master tanner.\n"
 "Caution: Slightly perishable.  Must be delivery fairly quickly.");
  set_mass(10);
  set_value(1);
  set_devobtimeperiod(60);
  set_dev_value(50);
  set_dev_exp(90);
}
