#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
  ::create();
  set_name("Queen");
  set("id",({"queen","pallo","pallomerlose","monster"}));
  set_level(33);
  set("short","Queen Pallo Merlose");
  set("long","The Queen cuddles with the king affectionately.");
  set("race","elf");
  set_gender("female");
  set_body_type("human");
  set_alignment(200);
  new(ARM "gown.c")->move(this_object());
  this_object()->force_me("wear gown");
  new(ARM "crown.c")->move(this_object());
  this_object()->force_me("wear crown");
  set("aggressive",1);
}
