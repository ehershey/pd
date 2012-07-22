
// monster file for waterworld-level 2
//      by ironman

#include <std.h>
#include <waterworld.h>


inherit MONSTER;

int counter,x;
void create() {
  ::create();
  set_name("nautilus");
  set_id(({"nautilus","cephalopod"}));
  set_short("a closed %^BLUE%^%^BOLD%^nautilus%^RESET%^%^RED%^");
  set_long("A closed %^BLUE%^%^BOLD%^Nautilus%^RESET%^ shell. It seems the animal is afraid and is hiding in its shell.");
  set_level(35);
  set_race("nautilus");
  set_body_type("squid");
  set_class("fighter");
  set_subclass("warrior");
  set_spells(({"whip","whirl","entangle"}));
  set_spell_chance(20);
  // equip loader
  counter=1+random(4);

  for(x;x<counter;x++) {
    new(WEP2"tentacle.c")->move(this_object());
    force_me("wield tentacle");
  }
  new(ITEMS2"nautilus_shell.c")->move(this_object());
  force_me("wear shell");
}
