// Coding by Whit
// Coded for Primal Darkness
// openpath_1.c

#include <std.h>
#include <citrin.h>
inherit ROOM;

void create() {
::create();
    set_short("Citrin Forest");
    set_day_long("The first impresions of this forest is the fact of it being "
		 "so dark. The trees waving in the trees make this area seem "
		 "very frightning.  The path is covered in small foot prints "
		 "of a very small animal.");
    set_night_long("The first impresions of this forest is the fact of it being "
		 "so dark. The trees waving in the trees make this area seem "
		 "very frightning.  The path is covered in small foot prints "
		 "of a very small animal.");

    set_properties(([
        "light" : 1,
        "night light" : 0,
        "forest" : 1,
    ]));
    set_exits(([
        "southeast" : ROOMS+"openpath_2.c",
    ]));
}
