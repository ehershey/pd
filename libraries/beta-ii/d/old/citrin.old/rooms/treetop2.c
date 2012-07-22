// Coding by Whit
// Coded for Primal Darkness
// treetop_2.c

#include <std.h>
#include <citrin.h>
inherit ROOM;

void create() {
::create();
    set_short("Amoung the Tree Tops");
    set_day_long("The walkway provides a spectacular view to the rest of the "
                 "forest.  The old ranger must have built this to navigate the "
                 "better than using the paths below.  The walkway is made from "
                 "wood.  There are cracks inbetween the boards giving a view "
                 "of the path below.");
    set_night_long("The walkway provides a spectacular view to the rest of the "
                 "forest.  The old ranger must have built this to navigate the "
                 "better than using the paths below.  The walkway is made from "
                 "wood.  There are cracks inbetween the boards giving a view "
                 "of the path below.");
    set_items(([
        "forest" : "If you are recieving this message please notify Whit.",
        "crack" : "Leaves have covered the hole and you are unable to see
through it",
    ]));
    set_properties(([
        "light" : 1,
        "night light" : 0,
        "forest" : 1,
    ]));
    set_exits(([
        "platform" : ROOMS+"treetop1.c",
        "east" : ROOMS+"treetop3.c"
    ]));
}
