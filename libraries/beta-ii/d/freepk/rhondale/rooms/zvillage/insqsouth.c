#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light": 2, "night light" : 2, "town" : 1]));
     set_name("Rhondale South");
     set_day_long("This path leads from the square to the south of Rhondale. Shops are set up on either side of the road, to the west is the local healer's shop, and east is the magic store. Many people walk past on their way to or from the square.");
     set_night_long("This path leads south from Rhondale square. Lamps light up the signs of shops to the east and west, the healing and magic stores respectively. At night the road is almost completely devoid of people.");
     set_exits(([
                "north"         : KEEPROOM"zvillage/[].c",
                "south"         : KEEPROOM"zvillage/inner06.c",
                "east"          : KEEPROOM"zvillage/stones.c",
                "west"          : KEEPROOM"zvillage/oils.c"
                ]));
}
