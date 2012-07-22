#include <std.h>
#include <arborlon.h>
inherit ROOM;

void create() {
::create();
    set_short("North of town square");
    set_long(
        "Dielko path leads north and south through the heart of Arborlon. "
        "The old dirt path leads north, right up to the castle gates. To "
        "the south is the town square. A small trail of smoke rises from "
        "the east."
    );
    set_items(([
        "smoke" : "A thin trail of smoke rises from the east.",
    ]));

    set_properties(([
        "light" : 2, "night light" : 1,
    ]));

    set_exits(([
        "south" : ROOMS "square.c",
        "north" : ROOMS "dielko_n1.c",
    ]));
}

void reset() {
    if(!present("townsman"))
	new(OBJ "townsman")->move(this_object());
}
