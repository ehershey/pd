#include <std.h>
#include <wildfire.h>
inherit OBJECT;
void create() {
  ::create();
  set_name("mill");
  set_short("A waterwheel");
  set_long("This structure is very tall. Attached to the building is a very large wheel, half immersed in water. The wheel slowly turns in the river's current. Near the top of the tower is a very large fan that spins steadily in the wind.");
  set_prevent_get("After grunting and groaning at the base of the mill for a few moments, you decide that your time would be better spend doing more productive things.");
  set_mass(800);
  set_id(({ "mill", "waterwheel", "windmill" }));
}
