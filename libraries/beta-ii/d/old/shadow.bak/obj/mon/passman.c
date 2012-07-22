#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
  ::create();
  set_name("drow");
  set("id",({"drow","thief","monster","passman","forger"}));
  set_level(39);
  set("short","A Sly Forger");
  set("long","This dirty scoundrel has obviously been forgeing passes for "
    "quite some time.  He snickers as you look him over.");
  set("race","drow");
  set_gender("male");
  set_body_type("human");
  set_alignment(-300);
  set_hp(2000);
  set_sp(300);
  new(OBJ "pass.c")->move(this_object());
  new(WEP "cursedagger.c")->move(this_object());
  this_object()->force_me("wield dagger");
  set("aggressive",1);
  set_class("rogue");
  set_subclass("assassin");
  set_spell_chance(100);
  set_spells(({"stab","backstab"}));
}
