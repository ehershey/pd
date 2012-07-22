#include <std.h>
#include <diran.h>

inherit RING;
void create() {
 ::create();
   set_name("ring");
   set_short("an %^BOLD%^%^GREEN%^emerald%^RESET%^ ring");
   set_long("A thin platinum band holds quite a large emerald to make this beautiful ring.");
   set_size(0);
set_material("metal");
   set_id(({ "ring", "emerald ring"}));
   set_mass(5);
   set_limbs(({"right hand", "left hand", "first hand", "second hand", "third hand", "fourth hand" }));
   set_type("ring");
   set_value(20+random(20));
   set_ac(1);
set_auto_load(20);
}
