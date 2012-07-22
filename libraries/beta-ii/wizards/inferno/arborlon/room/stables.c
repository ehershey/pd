#include <std.h>
#include <arborlon.h>
inherit ROOM;

void create() {
::create();
    set_short("The town stables");
    set_long(
        "The inside of the stables are short of clean. Hay and feed has "
        "been thrown about the ground. Several horses stand here, untied. "
        "The stables hands run around tending to the horses, ignoring you "
        "completely."
    );
    set_items(([
    ]));
    set_properties(([
        "light" : 1,
    ]));
    set_exits(([
        "east" : ROOMS "dielko_n2.c",
    ]));
}

void reset() {
    if(!present("statue"))
	new(OBJ "statue")->move(this_object());
    if(!present("royal horse")) {
	new(OBJ "horse")->move(this_object());
	new(OBJ "horse_f")->move(this_object());
	new(OBJ "horse")->move(this_object());
    }
}
