#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light": 2, "night light" : 2, "town" : 1]));
     set_short("Rhondale");
     set_day_long("The inner circle of Rhondale leads around the markets and through the homes of the town. The doors to a few houses can be seen, though they are all undoubtedly locked, and the guards would not look kindly on tresspassers. The road continues on to the southeast and west.");
     set_night_long("The inner circle of Rhondale leads around the markets and through the homes of the town. The doors to a few houses can be seen, though they are all undoubtedly locked, and a lamp shines over each one, clearly illuminating tresspassers. The road continues on to the southeast and west.");
     set_exits(([
                "southeast"		: KEEPROOM"zvillage/inner02.c",
                "west"			: KEEPROOM"zvillage/inner12.c"
                ]));
}
