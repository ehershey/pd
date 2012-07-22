#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
  ::create();
  set_name("prince");
  set("id",({"prince","lord","nichusar","monster"}));
  set_level(32);
  set("short","Prince Nichusar");
  set("long","The Prince is nervously checking himself in the mirror to get ready for his wedding.");
  set("race","elf");
  set_gender("male");
  set_body_type("human");
  set_alignment(200);
  new(WEP "lsword.c")->move(this_object());
  this_object()->force_me("wield sword");
  new(ARM "kingcape.c")->move(this_object());
  this_object()->force_me("wear cape");
  set("aggressive",1);
}
