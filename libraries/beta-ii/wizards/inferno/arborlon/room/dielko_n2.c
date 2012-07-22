#include <std.h>
#include <arborlon.h>
inherit ROOM;

void create() {
::create();
    set_short("Heading north on Dielko path");
    set_long(
        "You are getting even closer to the castle now, and it throws a "
        "long shadow across the path. A quick, refreshing breeze throws "
        "dirt from the path into your face. To the west are the town "
        "stables."
    );
    set_items(([
        "path" : "A second, smaller path leads to the east.",
        "castle" : "As you get closer to it, you are only more
impressed.",
    ]));

    set_properties(([
        "light" : 2, "night light" : 1,
    ]));

    set_exits(([
        "south" : ROOMS "dielko_n1.c",
        "north" : ROOMS "dielko_n3.c",
        "west" : ROOMS "stables.c",
    ]));
}
