#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
  ::create();
  set_name("head archer");
  set("id",({"archer","palacearcher","palace archer","monster"}));
  set_level(37);
  set("short","Head Archer");
  set("long","The archer has been around a while, and has seen many battles."
    "  He is currently working diligently on some papers at the desk.");
  set("race","elf");
  set_gender("male");
  set_body_type("human");
  set_alignment(100);
  new(OBJ "key2.c")->move(this_object());
  new(WEP "lbow.c")->move(this_object());
  this_object()->force_me("wield bow");
  new(ARM "larmour.c")->move(this_object());
  this_object()->force_me("wear armour");
  new(ARM "lquiver.c")->move(this_object());
  this_object()->force_me("wear quiver");
  set("aggressive",20);
  if(random(200) > 190) {
    new("/wizards/daboura/arm/dull_brass_shield.c")->move(this_object());
    command("wear shield");
  }
}
