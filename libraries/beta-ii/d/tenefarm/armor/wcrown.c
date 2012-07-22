#include <std.h>
#include <wildfire.h>
inherit ARMOUR;
void create() {
  ::create();
  set_name("aqua tiara");
  set_id(({ "tiara", "aqua tiara" }));
  set_short("%^BLUE%^A%^BOLD%^q%^CYAN%^u%^RESET%^a %^YELLOW%^T%^RESET%^i%^BOLD%^%^CYAN%^a%^BLUE%^r%^RESET%^%^BLUE%^a%^RESET%^");
  set_long("A tiara made of crystals that seem to be formed of pure water. The crystals have the surface consistancy of diamond, firm and cool to the touch. Upon closer inspection, you can see the water slowly flowing in a consistant pattern within the crystals. You can tell by the delicate yet sturdy structure of the tiara that it must have been made by somebody with an intense personal knowledge of elemental crafting, specifically water crafting.");
  set_ac(2);
  set_mass(1);
  set_type("helmet");
  set_curr_value("gold", 193);
  set_limbs( ({ "head" }) );
}
int query_auto_load() { return 1; }
