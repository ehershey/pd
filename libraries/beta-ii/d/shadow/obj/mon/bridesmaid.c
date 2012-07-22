#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
  ::create();
  set_name("maid");
  set("id",({"maid","bridesmaid","maids","monster"}));
  set_level(25);
  set("short","Bridesmaid");
  set("long","The maid attends to the Princess' every need.");
  set("race","elf");
  set_gender("female");
  set_body_type("human");
  set_alignment(200);
  new(ARM "bmdress.c")->move(this_object());
  this_object()->force_me("wear dress");
  set("aggressive",1);
}
