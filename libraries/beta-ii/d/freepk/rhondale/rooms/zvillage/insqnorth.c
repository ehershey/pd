#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light": 2, "night light" : 2, "town" : 1]));
     set_short("Rhondale North Road");
     set_day_long("This path leads from the square to the North of Rhondale. On either side of the road are local shops, east is the armour store, and to the west is the weaponsmith. Many people walk past on their way to or from the square.");
     set_night_long("This path leads north from Rhondale square. Lamps light up the signs of local shops. To the east is an armour store, and to the west a weaponsmith. Almost no one walks the road at night.");
     set_exits(([
                "north"         : KEEPROOM"zvillage/inner12.c",
                "south"         : KEEPROOM"zvillage/[].c",
                "east"          : KEEPROOM"zvillage/armour.c",
                "west"          : KEEPROOM"zvillage/weapon.c"
                ]));
}
