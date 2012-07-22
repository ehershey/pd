#include <std.h>
#include <waterworld.h>
inherit MONSTER;
void create()   {
  ::create();

  set_name("lobster");
  set_id(({"lobster"}));
  set_short("Delicious looking lobster");
  set_long("This is one delicious looking lobster. Its antennae wave around in search of food.");
  set_level(20);
  set_body_type("crab");
  set_race("lobster");
  set_class("rogue");
  set_subclass("assassin");
  set_money("gold",20);
  new(ITEMS2"lobster_tail.c")->move(this_object());
}
