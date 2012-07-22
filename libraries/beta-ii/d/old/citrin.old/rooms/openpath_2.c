// Coding by Whit
// Coded for Primal Darkness
// openpath_1.c

#include <std.h>
#include <citrin.h>
inherit ROOM;

void create() {
::create();
    set_short("Citrin Forest");
    set_day_long("The darkness is overwhelming.  The sun barly shines "
		 "through the tree tops of gigantic oak trees that grow "
		 "here.  There are small animal footprints here.");
    set_night_long("The darkness is overwhelming.  There are few "
	         "starts that can be seen throughthe tree tops of " 
	         "gigantic oak trees that grow here.  There are "
		 "small animal footprints here.");
    set_properties(([
        "light" : 1,
        "night light" : 0,
        "forest" : 1,
    ]));
    set_exits(([
        "northwest" : ROOMS+"openpath_1.c",
	"east" : ROOMS+"openpath_3.c",
    ]));
}
