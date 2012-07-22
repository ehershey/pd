#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light": 2, "night light" : 2, "town" : 1]));
     set_short("Rhondale East Road");
     set_day_long("This road leads from Rhondale square to the eastern quarter of the village. There isn't much of note here, since almost all trading goes on in the square, or just north and south of it.");
     set_night_long("This road leads from Rhondale square out to the eastern quarter of the village. The area is pretty plain with most of the trading going on in the square during the day. A few lamps provide enough light to see by.");
     set_exits(([
                "east"         : KEEPROOM"zvillage/inner03.c",
                "west"          : KEEPROOM"zvillage/[].c"
                ]));
}
