#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
  ::create();
  set_name("Shadowguard");
  set("id",({"guard","shadow","shadowguard","monster"}));
  set_class("fighter");
  set_level(30);
  set("short","A Shadowguard");
  set("long","Is he really there?..  The guard flickers back and "
      "forth, not letting you get a good look at him.");
set("race","elf");
  set_gender("male");
  set_body_type("human");
  set_alignment(-100);
  new(WEP "obsidsword.c")->move(this_object());
this_object()->force_me("wield sword");
  set("aggressive",5);
  set_spell_chance(15);
  //set_spells(({"whirl","slash"}));
  set_spells(({"slash"}));
}
