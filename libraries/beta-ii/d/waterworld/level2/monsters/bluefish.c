#include <std.h>
#include <waterworld.h>
inherit MONSTER;
void create()   {
  ::create();

  set_name("Bluefish");
  set_id(({"fish","bluefish"}));
  set_short("A fairly large bluefish is feeding off the smaller fish here.");
  set_long("The bluefish swims around, eating whatever small fish it can catch.");
  set_race("bluefish");
  set_body_type("fish");
  set_class("fighter");
  set_subclass("ranger");
  set_money("gold",100);
  set_spells(({"whip","whirl"}));
  set_spell_chance(30);
  set_level(27);
  set_stats("constitution",40);
  set_stats("dexterity",40);
  set_stats("strength",40);
  set_max_hp(3000);
  set_hp(3000);
  new(WEP2"bluefish_tail.c")->move(this_object());
  new(ITEMS1"fillet.c")->move(this_object());
  new(ITEMS1"fillet.c")->move(this_object());
  new(ITEMS1"fillet.c")->move(this_object());
  new(ITEMS1"fillet.c")->move(this_object());
  force_me("wield tail");
}
