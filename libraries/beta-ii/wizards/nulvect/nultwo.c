
#include <std.h>

inherit "/wizards/nulvect/std/user";

void create() {
  ::create();
  set_name("nultwo");
  set_race("human");
  //set_body_type("human");
  set_gender("male");
  set_id(({"nultwo"}));
  set_short("Nultwo");
  set_long("Nultwo is just this guy, you know?");
  set_level(25);
}

void save_player(string name) { return; }

string save_file_name(string name) {
  return sprintf("%s/%s", "/wizards/nulvect/save/", name);
}


