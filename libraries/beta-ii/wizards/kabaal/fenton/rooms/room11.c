#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
set_property("plain",1);
    set_short("Fenton City Limits");
    set_long(
      "You have now entered the more populated area of Fenton. This "
      "is where you'll find your shopkeepers, more houses, and mage "
      "tower.  You see a few shrubs along the path, as well as a boulder. "
    );
    set_items(([
        "boulder" : "A very large rock.",
        "shrubs" : "Dead shrubbery covers the side of the path.",
        "tower" : "It is rather large.  It rises into the sky to the west.",
    ]));
   set_listen("default", "The hustle and bustle of the town surrounds you.");
   set_exits( ([ 
        "south" : ROOMS"square.c",
        "east" : ROOMS"shop.c",
        "west" : ROOMS"room12.c",
    ]) );
}
