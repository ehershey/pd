//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "night light": 1, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("%^ORANGE%^This bridge extends just a little further north to connect between two tree-top platforms. Past those can be seen the trunk of what is possibly the biggest tree in the realm, stretching up beyond the clouds. The bridge also leads back to the south, away from this magnificent place.%^RESET%^");
     set_night_long("%^ORANGE%^This bridge extends just a little further north to connect between two tree-top platforms. Past those can be seen the trunk of what is possibly the biggest tree in the realm, it's top lost deep within the darkness of the night. The bridge also leads back to the south, away from this magnificent place.%^RESET%^");
     set_exits(([
		"south" : ELFROOM"bridge2-2.c",
		"north" : ELFROOM"moons4.c",
                ]));
}

