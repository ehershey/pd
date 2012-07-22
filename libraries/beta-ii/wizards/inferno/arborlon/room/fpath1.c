#include <std.h>
#include <arborlon.h>
inherit ROOM;

void create() {
::create();
    set_short("a small, dirt path");
    set_long(
        "You have wandered onto a small footpath to the east of Dielko "
        "road. An old shack is to the south. A thin trail of smoke rises "
        "from the shack."
    );
    set_items(([
        "smoke" : "Smoke rises from the shack to the south.",
        "shack" : "A small, old shack.";
    ]));
    set_properties(([
        "light" : 1, "night light" : 0,
    ]));

    set_exits(([
        "south" : ROOMS "fshack.c",
        "west" : ROOMS "dielko_n1.c",
    ]));
}
