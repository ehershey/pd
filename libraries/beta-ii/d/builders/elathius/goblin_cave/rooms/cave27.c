#include <std.h>

#include <caves.h>

inherit ROOM;

void create() {
::create();
    set_short("Inside the cave");
    set_long("As you look around the cave is like any other, dark, cold and eery. Small lanterns on the walls give enough light to see your self around the cave.\n");
    set_properties(([
	"light" : 1,
    ]));
    set_exits(([
	"west" : ROOMS "cave26.c",
	"south" : ROOMS "cave30.c",
	"southwest" : ROOMS "cave29.c",
    ]));
    set_smell("default", "The foul stench of goblins lurks about.");
    set_listen("default", "Clink ... Clink ... Clink ... ARGhhhhhhh!.");
}
