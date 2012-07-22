#include <std.h>
#include <lodos.h>
inherit MONSTER;
static int oi;

void create() {
    ::create();
    set_short("a beautiful bluejay");
    set_id( ({ "bird", "bluejay", "jay" }) );
    set_name("bluejay");
    set_level(17);
    set_long("The bluejay rustles it's feathers and twitches it's tail. "
      "It must have flown in through the window.");
    set_body_type("fowl");
    set_race("bird");
    set_gender("female");
}
