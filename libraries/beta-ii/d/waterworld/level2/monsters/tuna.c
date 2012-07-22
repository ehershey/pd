#include <std.h>
#include <waterworld.h>
inherit MONSTER;
void create()   {
  ::create();

  set_name("tuna");
  set_id(({"tuna","fish"}));
  set_race("tuna");
  set_level(14);
  set_short("happy looking tuna");
  set_long("The silvery fish looks very content to be swimming along just being a tuna, oblivious to the dangers around him.");
  set_gender("male");
  set_class("fighter");
  set_subclass("ranger");
  set_body_type("fish");
  new(ITEMS1"fillet.c")->move(this_object());
  new(ITEMS1"fillet.c")->move(this_object());
  new(ITEMS1"fillet.c")->move(this_object());
  new(ITEMS1"fillet.c")->move(this_object());
}
