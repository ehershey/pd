#include <std.h>

inherit FOOD;

void create() {
  ::create();
  set_name("cookie");
  set_id( ({ "cookie", "giant cookie", "a giant cookie" }) );
  set_weight(2);
  set_curr_value("gold", 0);
  set_short("a giant cookie");
  set_long("This cookie is about four feet in diameter. "
           "Your gaze causes it to magically change into your favorite kind of cookie.");
  set_strength(95);
}

int query_auto_load() {
  if (this_player()->query_name() == "nultest") return 1;
  return 0;
}
