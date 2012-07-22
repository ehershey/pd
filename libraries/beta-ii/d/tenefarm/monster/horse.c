#include <std.h>
#include <wildfire.h>
inherit MOUNT;
void create() {
  ::create();
  switch(random(50)) {
  case 1:
    set_name("%^BLUE%^blue horse");
    set_id( ({ "horse", "blue horse", "questbluehorse" }) );
    set_short("%^BLUE%^A blue horse");
    set_long("%^BLUE%^A pretty blue horse. Her mane is very clean, and she looks to be in top condition. Her coat glistens beautifully. She seems to be lost.");
    set_gender("female");
    set_race("horse");
    set_level(38);
    break;
  default:
    set_name("horse");
    set_id(({ "brown horse", "horse" }));
    set_short("A brown horse");
    set_long("A regular brown horse. He is kind of fat.");
    set_gender("male");
    set_race("horse");
    set_level(15);
    break;
  }
  set_body_type("equine");
}
