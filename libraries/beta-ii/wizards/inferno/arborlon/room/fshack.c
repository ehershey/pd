#include <std.h>
#include <arborlon.h>
inherit ROOM;

void create() {
::create();
    set_short("a small, dirt path");
    set_long(
        "Give me a description... PLEASE!"
    );
    set_items(([
        "smoke" : "The old fasioned stove has been lit.",
    ]));
    set_properties(([
        "light" : 1, "night light" : 0,
    ]));

    set_exits(([
        "north" : ROOMS "fpath1.c",
    ]));
}
