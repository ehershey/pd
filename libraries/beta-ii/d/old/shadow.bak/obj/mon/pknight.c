#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
  ::create();
  set_name("knight");
  set("id",({"knight","palaceknight","palace knight","monster"}));
  set_class("fighter");
  set_level(34);
  set("short","Palace Knight");
  set("long","He is one of the many proud protectors of the citizens of Tenebrae.");
  set("race","elf");
  set_gender("male");
  set_body_type("human");
  set_alignment(200);
  new(WEP "lsword.c")->move(this_object());
  this_object()->force_me("wield sword");
  new(ARM "larmour.c")->move(this_object());
  this_object()->force_me("wear armour");
  new(ARM "lgloves.c")->move(this_object());
  this_object()->force_me("wear gloves");
  set("aggressive",15);
  set_spell_chance(25);
  set_spells(({"whirl","slash"}));
}
