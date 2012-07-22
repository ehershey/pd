#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
  ::create();
  set_name("Chimney Sweep");
  set("id",({"sweep","worker","chimneysweep","monster"}));
  set_level(30);
  set("short","A Chimney Sweep");
  set("long","The Chimney Sweep smiles at you and and works away.");
  set("race","elf");
  set_gender("male");
  set_body_type("human");
  set_alignment(100);
  new(WEP "broom.c")->move(this_object());
  this_object()->force_me("wield broom");
  set("aggressive",10);
  set_spell_chance(20);
  set_spells(({"pummel"}));
}
