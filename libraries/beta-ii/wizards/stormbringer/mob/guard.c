// Coded by Whit
#include <citrin.h>
#include <std.h>
inherit MONSTER;
void create() {
::create();
set_name("tombar guard");
set_id(({"guard", "tombar guard"}));
  set_class("mage");
  set_subclass("wizard");
  set_level(33);
set_short("tombar guard");
set_long("This is a tombar guard.  He garuds the sacred temples hidden secrets.");
set("race", "dwarf");
set_gender("male");
  set_body_type("human");
set_alignment(100);
new(ROOM2"tombar/arm/guardarm")->move(this_object());
this_object()->force_me("wear armour");
new(ROOM2"tombar/wep/guardwep.c")->move(this_object());
this_object()->force_me("wield sword");
add_money("gold", random(100));
  set("aggressive",1);
  set_spell_chance(100);
  set_spells(({"fireball"}));
}
