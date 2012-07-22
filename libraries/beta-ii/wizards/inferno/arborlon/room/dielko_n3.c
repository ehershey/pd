#include <std.h>
#include <arborlon.h>
inherit ROOM;

void create() {
::create();
    set_short("South of a castle");
    set_long(
        "You are to the south of the marble castle. It stands before you "
        "like a giant, large stone pillars looming into the sky, sending "
        "a huge shadow down the entire path."
    );
    set_items(([
        "path" : "A second, smaller path leads to the east.",
        "castle" : "As you get closer to it, you are only more impressed.",
    ]));

    set_properties(([
        "light" : 1,
    ]));

    set_exits(([
        "south" : ROOMS "dielko_n2.c",
        "north" : ROOMS "dielko_n4.c",
    ]));
}
