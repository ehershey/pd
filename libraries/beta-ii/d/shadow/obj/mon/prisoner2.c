#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
  ::create();
  set_name("prisoner");
  set("id",({"prisoner","rouge","monster"}));
  set_level(24);
  set("short","Prisoner of Tenebrae");
  set("long","The prisoner is a dirty, swarthy fellow.");
  set("race","elf");
  set_gender("male");
  set_body_type("human");
  set_alignment(0);
  set("aggressive",1);
  new(OBJ "bauble.c")->move(this_object());
  set_emotes(10, ({"Prisoner looks about wildly and exclaims \"I have seen the true power and survivied!!\""}), 0);
}
