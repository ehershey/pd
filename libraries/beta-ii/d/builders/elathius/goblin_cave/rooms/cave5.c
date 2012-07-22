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
	"northeast" : ROOMS "cave6.c",
	"northwest" : ROOMS "cave49.c",
	"south" : ROOMS "cave4.c",
    ]));
    set_smell("default", "The foul stench of goblins lurks about.");
    set_listen("default", "Clink ... Clink ... Clink ... ARGhhhhhhh!.");
}

void reset() {
    if(!present("goblin"))
	new(MONSTERS"normal_goblin.c") ->move(this_object());
	new(MONSTERS"normal_goblin.c") ->move(this_object());
	new(MONSTERS"slave_dwarf.c") ->move(this_object());
	new(MONSTERS"slave_dwarf.c") ->move(this_object());
}
