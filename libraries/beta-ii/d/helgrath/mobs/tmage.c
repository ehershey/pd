#include <std.h>
#include <helgrath.h>
inherit MONSTER;

create() {
  ::create();
  set_name("teacher");
  set_id( ({"teacher","mage teacher", "mage"}) );
  set_short("Mage Teacher");
  set_level(33+random(3));
  if(random(2)) set_gender("male");
  else set_gender("female");
  set_long("This mage is overseeing the students, giving them advice on how to better manipulate their spells.");
  set("race", "elf");
  set_alignment(300);
  set_body_type("human");
   if(random(100)>98) {
  new(ARM"mrobes")->move(this_object());
  command("wear robes");
   }
  set_subclass("pyromancer");
  set_swarm(1);
  set_spells(({"flamebraid"}));
  set_spell_chance(30);
}
