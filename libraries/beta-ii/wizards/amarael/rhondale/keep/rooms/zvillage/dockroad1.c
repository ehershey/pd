#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light": 2, "night light" : 1, "town" : 1]));
     set_name("Rhondale");
     set_short("Rhondale");
     set_day_long("The docks of Rhondale end here as they reach the city walls. Two huge iron gates stand open, allowing free passage to all those who wish to enter the city. Many people pass by, most carrying loads of various fish from the catch-boats.");
     set_night_long("The docks of Rhondale end here as they reach the city walls. Two huge gates stand just partially open, restricting passage through them. AT night the place is deserted, the lapping waves and groaning wood making eerie noises for a night-time stroll.");
     set_exits(([
                "west"                  : KEEPROOM"zvillage/dockroad2.c",
		"gate"			: KEEPROOM"zvillage/dockgate.c"
                ]));
     set_listen("default", "Waves lap up at the wooden pylons and the wood underfoot groans with every step.");
}
