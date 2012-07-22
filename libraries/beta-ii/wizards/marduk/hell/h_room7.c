#include <std.h>
inherit ROOM;

void create() {
::create();
    set_short("winding stairway");
    set_long("%^YELLOW%^%^BLACK%^You are on your way down a winding stairway. "
		"It is pitch black, besides the soft %^YELLOW%^rays %^BLACK%^ "
                "emitted from a single %^YELLOW%^torch%^BLACK%^ on the wall.");
    set_items(([
	"torch" : "The torch casts a dull %^YELLOW%^light.",
    ]));
    set_properties(([
        "light" : 1,
    ]));
    set_exits(([
        "east" : "/wizards/marduk/hell/h_room6.c",
        "down" : "/wizards/marduk/hell/h_room10.c",
    ]));
}
