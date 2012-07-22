// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
::create();
set_name("Faerie Village");
set_day_long("The faeries are constantly moving about "
"doing there every day chores.  Many fly to nearby stores. "
"There buildings sit under 2 feet tall.  The building "
"represent a small business district.  A small faerie "
"flutters by making a small buzz sound.  The faeries don't "
"seem alarmed by your presence.");
set_night_long("The faeries are inactive in the night.  "
"There poor vision makes it hard to see more than 2 inches "
"in front of there faces.  Many small buildings surround this "
"small area.  The building are made up of stores and "
"bussinesses.");

set_properties(([ "light" : 1, "night light" : 1, "village" : 1 ]));
set_exits(([
"southwest" : ROOMS"fvillagee.c",
"north" : ROOMS"fvillage2.c",
]));
}

