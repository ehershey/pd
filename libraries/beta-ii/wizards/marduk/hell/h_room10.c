#include <std.h>
inherit ROOM;

void create() {
::create();
    set_short("winding stairway");
    set_long("%^BOLD%^%^BLACK%^You are on your way down a winding stairway. "
                "It is pitch black, besides the soft %^YELLOW%^rays%^RESET%^ "
                "%^BOLD%^%^BLACK%^emitted from a single %^YELLOW%^torch %^BOLD%^%^BLACK%^on the wall.");
    set_items(([
        "torch" : "The torch casts a dull light.",
    ]));
    set_properties(([
        "light" : 1,
    ]));
    set_exits(([
      "east" : "/wizards/marduk/hell/h_room11.c",
        "up" : "/wizards/marduk/hell/h_room7.c",
    ]));
}

void reset() {
     if(!present("spectre"))
        new("/wizards/marduk/hell/spectre.c")->move(this_object());
}
