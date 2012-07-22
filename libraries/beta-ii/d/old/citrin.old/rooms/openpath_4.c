// Coding by Whit
// Coded for Primal Darkness

#include <std.h>
#include <citrin.h>
inherit ROOM;

void create() {
::create();
    set_short("Citrin Forest");
    set_day_long("The forest path weaves around a large oak tree to the north. "
		 "The tree is covered with a very thick bark.  Something can be "
		 "seen high above.  Look above you see a platform of somekind. "
		 "the path continues to the northeast and northwest bypassing this "
		 "magnificent tree.");
    set_night_long("The forest path weaves around a large oak tree to the north. "
		 "The tree is covered with a very thick bark.  Something can be "
		 "seen high above.  Look above you see a platform of somekind. "
		 "the path continues to the northeast and northwest bypassing this "
		 "magnificent tree.");

    set_properties(([
        "light" : 1,
        "night light" : 0,
        "forest" : 1,
    ]));
    set_exits(([
        "northwest" : ROOMS+"openpath_3.c",
        "northeast" : ROOMS+"openpath_5.c",
    ]));
}
