#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
  ::create();
  set_name("jester");
  set("id",({"jester","fool","kings jester","monster"}));
  set_level(28);
  set("short","The Jester");
  set("long","The jester is a fool who runs around poking fun at people.");
  set("race","elf");
  set_gender("male");
  set_body_type("human");
  set_alignment(0);
  set_overall_ac(6);
  new(ARM "jcap.c")->move(this_object());
  this_object()->force_me("wear cap");
  set("aggressive",1);
  set_emotes(10, ({"Jester exclaims: \"Then I blew a big booger at him!\"\nThe guests laugh politely."}), 0);
}
