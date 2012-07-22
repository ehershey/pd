#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
  ::create();
  set_name("magician");
  set("id",({"magician","mage","kings mage","monster"}));
  set_class("mage");
  set_subclass("wizard");
  set_level(33);
  set("short","The King's Mage");
  set("long","The lanky mage looks coldy over the gathering.");
  set("race","elf");
  set_gender("male");
  set_skill("nature", 150);
  set_body_type("human");
  set_alignment(100);
  new(ARM "mrlight.c")->move(this_object());
  this_object()->force_me("wear robes");
  new(WEP "mcane.c")->move(this_object());
  this_object()->force_me("wield cane");
  set("aggressive",1);
  set_spell_chance(10);
  set_spells(({"bolt"}));
}
