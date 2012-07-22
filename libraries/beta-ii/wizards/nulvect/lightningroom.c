#include <std.h>

inherit PERIODIC_ROOM;

void create() {
  ::create();
  set_period(4);
}

int periodic() {
  object to = this_object();
  object *all = filter(all_inventory(to), (: $1->is_living() :) );

  if (!sizeof(all)) return 0;

  if (random(100) < 35) {
    foreach (object who in all) {
      if (random(100) < 30) {
        message("info", "%^YELLOW%^A bolt of lightning strikes you!%^RESET%^", who);
        message("info", "%^YELLOW%^A bolt of lightning strikes "+who->query_cap_name()+"!", to, who);
        who->add_hp(-(30+random(30)));
      }
    }
  }
  else if (random(100) < 40) {
    message("info", "%^WHITE%^A loud thunderclap suddenly splits the air.%^RESET%^", to);
    foreach (object who in all) {
      if (random(100) < 20) {
        message("info", "%^WHITE%^The thunder frightens you!%^RESET%^", who);
        who->set_paralyzed(2, "You are too frightened to move.");
      }
    }
  }

  return 1;
}
