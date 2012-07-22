#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Market Road");
    set_long("A roughly hewn statue dominates the center of the street, depicting "
      "what appears to be some sort of ancient warrior. The statue's left arm has "
      "fallen from its perch above the ground and tumbled to the ground, shattering "
      "the warrior's once finely crafted sword. His right arm, wielding a the "
      "depiction of a magnificent heater shield, guards the air, as if to deflect "
      "the firery onslaught of some huge airborn daemon." );
    set_exits( ([ "west" : ROOMS "marketrd_e02.c",
      "east" : ROOMS "marketrd_e04.c",
      "north" : ROOMS "shop_weapons.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "The sounds of local gossip fill the air.");

}
