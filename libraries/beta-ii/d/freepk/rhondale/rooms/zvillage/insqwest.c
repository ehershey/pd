#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light": 2, "night light" : 2, "town" : 1]));
     set_short("Rhondale East Road");
     set_day_long("This road leads west from Rhondale square out to the docks. Lamps are set up on either side of the path to give light during the night. Occasionaly a local walks by on day to day business.");
     set_night_long("This road leads west from Rhondale square out to the docks. Lamps are set up on either side of the path to give light during the night. Almost none of the locals are out here at night.");
     set_exits(([
                "east"         : KEEPROOM"zvillage/[].c",
                "west"          : KEEPROOM"zvillage/inner09.c"
                ]));
}
