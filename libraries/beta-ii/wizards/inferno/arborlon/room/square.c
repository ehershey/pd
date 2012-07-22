#include <std.h>
#include <arborlon.h>
inherit ROOM;

void create() {
::create();
    set_short("Arborlon square");
    set_long(
        "You are in the well-known Arborlon town square. Arborlon is a "
        "fairly large and popular town. Arborlon is the intersection "
        "of several other nations and kingdoms, making it a popular "
        "gathering place for adventurers. An intricate statue has been "
        "built in the center of the square."
    );
    set_items(([
        "mist" : "A thin, blue cloud of mist surrounds the statue.",
    ]));

    set_property("light", 3);
    set_exits(([
        "north" : ROOMS "north.c",
    ]));
}

void reset() {
    if(!present("statue"))
	new(OBJ "statue")->move(this_object());
}
