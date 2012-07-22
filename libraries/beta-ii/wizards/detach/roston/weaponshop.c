#include <std.h>
inherit ROOM;

void create() {
  ::create();         

set_name("Weapon Shop");
set_properties((["light":2, "night light":3]));
set_short("Roston Weapon Shop");
set_long("Welcome to the Roston weapon shop. There are tons "
         "of metal pices all over the floor, the weapon shop "
         "is for buying or selling weapons, if you wish to buy "
         " or sell talk to Mr. Green the shop owner");

set_exits((["east":"/wizards/detach/roston/roston13",
            "west":"/wizards/detach/roston/weaponstorage"]));
}                                                        
