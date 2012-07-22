#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light": 2, "night light" : 2, "town" : 1]));
     set_name("Rhondale South Road");
     set_short("Rhondale South Road");
     set_long("This road connects the southern parts of the inner and outer circles of Rhondale to each other. To either side of the road can be seen a few run-down houses of commoners. Very few people take this path since there is nothing of interest on this side of the village.");
     set_exits(([
                "north"         : KEEPROOM"zvillage/inner06.c",
                "south"         : KEEPROOM"zvillage/outer0600.c",
                ]));
}
