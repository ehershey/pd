#include <std.h>
#include <wildfire.h>
inherit MONSTER;
void create() {
  ::create();
  set_name("farmer");
  set_id( ({ "man", "farmer", "human" }) );
  set_short("The farmer");
  set_long("The farmer sits on his knee facing the wall. He appears to be working on something in the windmill.");
  set_gender("male");
  set_race("human");
  set_body_type("human");
  set_level(21);
}
