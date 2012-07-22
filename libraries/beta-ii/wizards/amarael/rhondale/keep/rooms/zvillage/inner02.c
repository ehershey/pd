#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light": 2, "night light" : 2, "town" : 1]));
     set_short("Rhondale");
     set_day_long("The inner circle of Rhondale leads around the markets and through the homes of the town. The doors to a few houses can be seen, most are locked, though one on the east side of the road is open. The road continues on to the northwest and south.");
     set_night_long("The inner circle of Rhondale leads around the markets and through the homes of the town. The doors to a few houses can be seen, though most are undobtedly locked, one to the east has the door open just a tad. The road continues on to the northwest and south.");
     set_exits(([
                "northwest"             : KEEPROOM"zvillage/inner01.c",
                "south"                 : KEEPROOM"zvillage/inner03.c",
		"east"			: KEEPROOM"zvillage/smithy.c"
                ]));
}
