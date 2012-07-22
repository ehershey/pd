#include <std.h>
#include <dquest.h>
inherit ROOM;

void create() {
::create();
set_short("A cave lit by several torches");
set_long("%^BOLD%^BLACK%^You have been magically teleported into a large cave that is being lit by several torches mounted along the walls.  You can see strange runes glowing in various colors carved into the stone floor.  A tunnel leads to the northwest.");  
set_properties((["light" : 2, "indoors" : 1, "no teleport":1]));
set_exits(([
"northwest": DQUEST "dquest2.c",
]));
set_items(([
"runes": "The runes are of various colors and of various shapes.  However in this room a %^BOLD%^RED%^red %^RESET%^ram's head seems to flicker slightly.",
"torches": "The torches are glowing with strange flames that dont seem to radiate heat of any kind.  You notice that the torch mounts are not actually fastened to the cave walls, but are magically suspended in air and are impossible to move.",
"walls": "The cave walls are rough and jagged yet the floor is strangely smooth.",
"floor": "The floor is covered with many strange runes.",
]));
}

void reset() {
::reset();
if(!present("peace")) {
new(DQUEST "peace.c")->move(this_object());
}
}
