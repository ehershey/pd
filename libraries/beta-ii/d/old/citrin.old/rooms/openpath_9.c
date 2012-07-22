// Coding by Whit
// Coded for Primal Darkness
// openpath_9.c

#include <std.h>
#include <citrin.h>
inherit ROOM;

void create() {
::create();
    set_short("Citrin Forest");
    set_day_long("This section of the forest is dark.  There is not much light "
		 "that comes through the tree tops.  The slight breeze make the "
"tree sway in the wind.  The is a bush patch to the north.");
    set_night_long("This section of the forest is dark.  There is not much light "
		 "that comes through the tree tops.  The slight breeze make the "
		 "trees sway in the wind.");

    set_properties(([
        "light" : 1,
        "night light" : 0,
        "forest" : 1,
    ]));
    set_listen("default", "Scratching sounds can be heard in the distance.");
    set_exits(([
        "northwest" : ROOMS+"openpath_8.c",
        "southwest" : ROOMS+"openpath_.c",
"north" : ROOMS+"bushes4",
    ]));
}
