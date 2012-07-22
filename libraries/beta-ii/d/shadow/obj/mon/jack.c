#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
  ::create();
  set_name("Little Jack Horner");
  set("id",({"boy","jack","horner","monster","jack horner"}));
 set_class("fighter");
  set_level(20);
  set("short","Little Jack Horner");
  set("long","Jack smiles at you as he wiggles his thumb around in his pie.");
set("race","human");
  set_gender("male");
  set_body_type("human");
  set_alignment(400);
  set_overall_ac(4);
  set_hp(700);
  set_sp(300);
  new(WEP "jthumb.c")->move(this_object());
  new(OBJ "pie.c")->move(this_object());
  this_object()->force_me("wield thumb");
  set_skill("melee",50);
  set_skill("blunt",100);
  set_skill("attack",50);
  set_skill("defense",70);
  set_stats("dexterity",50);
  set("aggressive",1);
  set_emotes(20, ({"Jack exclaims, \"What a good boy am I!\""}), 0);
}
