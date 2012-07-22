#include <std.h>
#include <helgrath.h>
inherit MONSTER;

create() {
  ::create();
  set_name("mage");
  set_id( ({"mage","studying mage"}) );
  set_short("Studying Mage");
  set_level(28+random(4));
  if(random(2)) set_gender("male");
  else set_gender("female");
  set_long("The mage is studying throughly, poring over a stack of books at "+
    possessive(this_object())+" feet.  Glancing up at you, "+nominative(this_object())+
    " nods at you and goes back to work.");
  set("race", "elf");
  set_alignment(200);
  set_body_type("human");
   if(random(100)>95) {
  //new(AM"mrobes")->move(this_object());
  command("wear robes");
   }
}
