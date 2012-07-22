#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_id( ({"santa", "santa's head", "head", "stake"}) );
  set_short("a stake with a head stuck on the end");
  set_name("a stake");
  set_long("A sharp stake stands here, stuck into the ground. Impaled on the sharp "
           "end is a human head. The face looks old and, somehow, still a bit jolly. "
           "A now shaggy white beard hangs down from the chin, and the red and white "
           "hat is still perched atop the head.");
  set_prevent_get("It is stuck in the ground.");
  set_weight(6);
}
