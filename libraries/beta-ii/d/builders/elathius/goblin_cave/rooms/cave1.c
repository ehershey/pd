#include <std.h>

#include <caves.h>

inherit ROOM;

void create() {
::create();
    set_short("Inside the cave");
    set_long("Before you a long dark passageway hollows out this cave. Cool water drips from the roof of the cave. Small lanterns along the cave wall give the small but sufficient enough to look around these dark caves.\n");
    set_properties(([
	"light" : 1,
    ]));
    set_exits(([
	"north" : ROOMS "cave2.c",
	"out" : ROOMS "room4.c",
    ]));
    set_smell("default", "The foul stench of goblins lurks about.");
    set_listen("default", "Clink ... Clink ... Clink ... ARGhhhhhhh!.");
}

void reset() {
    if(!present("goblin"))
	new(MONSTERS"weak_goblin.c") ->move(this_object());
}
