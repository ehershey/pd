#include <std.h>
#include <wildfire.h>
inherit MONSTER;
void create() {
  ::create();
  set_name("woman");
  set_id( ({ "woman", "pretty woman", "youngwoman" }) );
  set_short("A very pretty woman");
  set_long("This woman seems to have found a nice place to hide out with her boyfriend, but she seems to be having a hard time finding him amidst the hay.");
  set_gender("female");
  set_race("human");
  set_body_type("human");
  set_level(17);
}
