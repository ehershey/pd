//Drackypoo.  020203
#include <std.h>
inherit "/std/deliv_object.c";
void create(){
::create();
  set_name("package");
  set_id(({ "package_sage", "delivery package" }));
  set_short("a small package");
  set_long("A small package.  It reads:\n\nTO: The Sage of Tirun");
  set_mass(10);
  set_value(1);
  set_devobtimeperiod(180);
// He's a patient old man.
  set_dev_value(30);
// However, not rich.
  set_dev_exp(60);
// But he is experienced :)
}
