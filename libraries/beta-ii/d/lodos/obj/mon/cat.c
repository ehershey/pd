#include <std.h>
#include <lodos.h>
inherit MONSTER;
static int oi;

void create() {
 ::create();
   set_short("an impatient cat");
   set_id(({ "cat", "impatient cat" }));
   set_name("cat");
   set_level(21);
   set_long("An orange cat with black stripes.");
   set_body_type("quadrupe");
   set_race("cat");
   set_gender("male");
}
