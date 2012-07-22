#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
  ::create();
  set_name("King");
  set("id",({"king","lord","cloud","monster"}));
  set_level(34);
  set("short","King Cloud");
  set("long","The honorable King Cloud watches the festivities.");
  set("race","elf");
  set_gender("male");
  set_body_type("human");
  set_alignment(200);
  new(WEP "rsword.c")->move(this_object());
  this_object()->force_me("wield sword");
  new(ARM "fancyarmour.c")->move(this_object());
  this_object()->force_me("wear armour");
  new(ARM "kingcape.c")->move(this_object());
  this_object()->force_me("wear cape");
  set("aggressive",1);
}
