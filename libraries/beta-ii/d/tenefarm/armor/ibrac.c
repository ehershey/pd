#include <std.h>
#include <wildfire.h>
inherit ARMOUR;
void create() {
  ::create();
  set_name("bracelets");
  set_id(({ "bracelet", "ivy bracelets", "bracelets" }));
  set_wear("As you slip the bracelets on over your wrists you feel a strange surge of power.");
  set_remove("You sigh softly as you take off your ivy bracelets.");
  set_short("%^CYAN%^%^BOLD%^A P%^RESET%^%^BLUE%^%^BOLD%^ai%^RESET%^%^CYAN%^%^BOLD%^r %^RESET%^%^BLUE%^of %^RESET%^%^CYAN%^%^BOLD%^I%^RESET%^%^BLUE%^v%^BOLD%^%^RESET%^%^CYAN%^%^BOLD%^y %^BLUE%^Brac%^WHITE%^le%^CYAN%^%^BOLD%^ts%^RESET%^");
  set_long("A pair of thick bracelets of mysterious origin. The bracelets are inlaid with a thick intricate pattern of dark blue and light green ivy.");
  set_ac(2);
  set_mass(3);
  set_type("bracelet");
  set_limbs(({ "right hand", "left hand" }));
  set_curr_value("gold", 100);
}
int query_auto_load() { return this_player()->query_level() >= 30; }
