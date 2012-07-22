#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
  ::create();
  set_name("guard");
  set("id",({"guard","palaceguard","palace guard","monster"}));
  set_class("fighter");
  set_level(31);
  set("short","Palace Guard");
  set("long","He is one of the many proud protectors of Tenebrae and it's king.");
  set("race","elf");
  set_gender("male");
  set_body_type("human");
  set_swarm(1);
  set_alignment(100);
  new(WEP "lspear.c")->move(this_object());
  this_object()->force_me("wield spear");
  new(ARM "larmour.c")->move(this_object());
  this_object()->force_me("wear armour");
  new(ARM "lgloves.c")->move(this_object());
  this_object()->force_me("wear gloves");
  set("aggressive",20);
  set_spell_chance(20);
  set_spells(({"whirl","slash"}));
}
