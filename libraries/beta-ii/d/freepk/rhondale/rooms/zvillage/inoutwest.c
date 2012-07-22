#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light": 2, "night light" : 2, "town" : 1]));
     set_name("Rhondale West Road");
     set_short("Rhondale West Road");
     set_long("This road connects the western parts of the inner and outer circles of Rhondale to each other. To either side of the road can be seen the houses of local fisherman and sailors. This road is fairly well traveled with the daily movements the dockworkers.");
     set_exits(([
                "west"          : KEEPROOM"zvillage/outer0900.c",
                "east"          : KEEPROOM"zvillage/inner09.c",
                ]));
}
