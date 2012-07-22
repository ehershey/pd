#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
  ::create();
  set_name("dog");
  set("id",({"dog","canine","zanzabar","monster"}));
  set_level(23);
  set("short","Zanzabar-The Court Mutt");
  set("long","The dog wags its tail and looks at you.");
  set("race","mutt");
  set_gender("male");
  set_body_type("canine");
  set_alignment(-100);
  set("aggressive",30);
  new(ARM "scollar.c")->move(this_object());
  this_object()->force_me("wear collar");
}
