#include <std.h>;
#include <shadow.h>;

inherit "/std/police";

void create() {
  ::create();
  set_name("Shadowguard Sheriff");
  set("id",({"guard","shadow","shadowguard","monster","sheriff"}));
  set_class("fighter");
  set_level(30);
  set("short","A Shadowguard Sheriff");
  set("long","This dark guard stands menacingly, daring any to "
      "his upholding of the rules.");
  set("race","elf");
  set_gender("male");
  set_body_type("human");
  set_alignment(-100);
  new(WEP "obsidsword.c")->move(this_object());
  this_object()->force_me("wield sword");
  set("aggressive",5);
  set_spell_chance(15);
  set_spells(({"whirl","slash"}));
}
