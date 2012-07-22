#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light": 2, "night light" : 2, "town" : 1]));
     set_name("Rhondale North Road");
     set_short("Rhondale North Road");
     set_long("This road connects the northern parts of the inner and outer circles of Rhondale to each other. To either side of the road can be seen the houses of town officials and guardsmen. This road is fairly well traveled with all the patrols heading out around the city.");
     set_exits(([
                "north"         : KEEPROOM"zvillage/outer1200.c",
                "south"         : KEEPROOM"zvillage/inner12.c",
                ]));
}
