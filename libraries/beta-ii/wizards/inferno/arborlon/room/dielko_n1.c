#include <std.h>
#include <arborlon.h>
inherit ROOM;

void create() {
::create();
    set_short("Heading north on Dielko path");
    set_long(
        "Dielko is an old, dirt path from the founding days of Arborlon. "
        "A smaller path starts here and leads east, then curves south. "
        "A large marble castle stands to the north in all it's majesty. A "
        "Thin trail of smoke rises from the southeast."
    );
    set_items(([
        "smoke" : "A thin trail of smoke rises from the southeast.",
        "path" : "A second, smaller path leads to the east.",
        "castle" : "Impressive, even from here.",
    ]));

    set_properties(([
        "light" : 2, "night light" : 1,
    ]));

    set_exits(([
        "south" : ROOMS "north.c",
        "north" : ROOMS "dielko_n2.c",
        "east" : ROOMS "fpath1.c",
    ]));
}
