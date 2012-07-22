#include <std.h>
inherit ROOM;

void create() {
::create();
    set_short("winding stairway");
    set_long("%^YELLOW%^%^BLACK%^You are on your way down a winding stairway. "
		"It is pitch black, besides the soft %^YELLOW%^rays %^BLACK%^ "
                "emitted from a single %^YELLOW%^torch%^BLACK%^ on the wall.");
    set_items(([
        "torch" : "Hrmm, the light off the torch seems to reveal an exit to the north.",
    ]));
    set_properties(([
        "light" : 1,
    ]));
    set_exits(([
        "up" : "/wizards/marduk/hell/h_room5.c",
        "north" : "/wizards/marduk/hell/h_room8.c",
        "west" : "/wizards/marduk/hell/h_room7.c",
    ]));
    add_invis_exit("north");
}
void reset() {
   ::reset();
    if(!present("guard"))
    new("/wizards/marduk/hell/crim_guard3.c")->move(this_object());
    new("/wizards/marduk/hell/crim_guard4.c")->move(this_object());
    }
