#include <wiz.h>
inherit MONSTER;

void create() {
 ::create();
  set_name("h0h0tr0n");
  set_id( ({"h0h0tr0n", "h0h0" }) );
  set_short("An evil h0h0tr0n");
  set_long("An evil creature of wiz's cellar.");
  set_level(15);
  set_race("dragon");
  set_class("dragon");
  set_subclass("storm");
  set_gender("male");
  set_body_type("dragon");
   new("/d/arlon/room/wizhouse/arm/wingclaws.c")->move(this_object());
  force_me("wear wingclaws");
}
