// Coding by Whit
// Coded for Primal Darkness

#include <std.h>
#include <citrin.h>
inherit ROOM;

void create() {
::create();
    set_short("Citrin Forest");
    set_day_long("The soft padding of the undergrowth help with the fall "
		 "shack.  It looks like you can reach the path from here to "
		 "the east.  Perhaps all hope is not lost.");
    set_night_long("The soft padding of the undergrowth help with the fall "
		 "shack.  It looks like you can reach the path from here to "
		 "the east.  Perhaps all hope is not lost.");
    set_properties(([
        "light" : 1,
        "night light" : 0,
        "forest" : 1,
    ]));
    set_exits(([
"east" : ROOMS+"bushes2.c",
    ]));
}
