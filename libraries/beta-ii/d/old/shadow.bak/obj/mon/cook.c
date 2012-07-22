#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
  ::create();
  set_name("Cook");
  set("id",({"cook","chef","monster"}));
  set_level(26);
  set("short","A Cook");
  set("long","The Cook bustles from pot to pot.");
  set("race","elf");
  set_gender("male");
  set_body_type("human");
  set_alignment(100);
  set_overall_ac(5);
  new(WEP "bknife.c")->move(this_object());
  this_object()->force_me("wield knife");
  set("aggressive",5);
}
