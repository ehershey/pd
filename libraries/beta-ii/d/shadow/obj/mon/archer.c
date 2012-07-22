#include <std.h>
#include <shadow.h>

inherit MONSTER;

void create() {
  ::create();
  set_name("archer");
  set("id",({"archer","palacearcher","palace archer","monster"}));
  set_level(32);
  set("short","Palace Archer");
  set("long","This archer perches in Tenebrae tower, protecting it's inhabitants.");
  set("race","elf");
  set_gender("male");
  set_body_type("human");
  set_alignment(100);
  new(WEP "lbow.c")->move(this_object());
  this_object()->force_me("wield bow");
  new(ARM "larmour.c")->move(this_object());
  this_object()->force_me("wear armour");
  new(ARM "lquiver.c")->move(this_object());
  this_object()->force_me("wear quiver");
  set("aggressive",20);
}
