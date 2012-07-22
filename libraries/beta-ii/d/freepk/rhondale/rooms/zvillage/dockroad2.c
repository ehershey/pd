#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light": 2, "night light" : 1, "town" : 1]));
     set_name("Rhondale");
     set_short("Rhondale");
     set_day_long("Here the Rhondale docks manage to get out over shallow ocean. There are many places for boats to tie up, though almost all of them are empty. Every dozen metres a catch-boat is unloading it's cargo, with someone ferrying it into the town.");
     set_night_long("Here the Rhondale docks manage to get out over shallow ocean. Scores of empty boats are tied up for the night, with almost no room between them. At night no one is out here, as the creaks and groans of the dock make eerie noise that ward off casual strollers.");
     set_exits(([
                "west"                  : KEEPROOM"zvillage/docks.c",
		"east"			: KEEPROOM"zvillage/dockroad1.c"
                ]));
     set_listen("default", "Waves lap up at the wooden pylons and the wood underfoot groans with every step.");
}
