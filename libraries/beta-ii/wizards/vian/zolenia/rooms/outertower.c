#include <std.h>
#include <zolenia.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "indoors" : 1, "night light" : 1]) );
set_smell("default", "The smell of freshly cut wood fills the tower.");
set_listen("default", "The sound of arrows hitting practice targets and the cutting of arrows echoes throughout the tower.");
set_short("an archer's tower");
set_long("The tower made of onyx has racks of bows lining the walls and nothing in the center, except for a spiraling staircase.  The floor is wet with blood, and there are piles of bones lined up against the walls.  There is a dim light glowing from above.");
set_items(([
({"ground", "floor", "blood"}) : "The ground, a smooth slab of onyx, is covered in small puddles of blood.",
"onyx" : "The entire tower appears to be made of onyx.",
({"racks", "rack", "walls", "bows"}) : "The walls are lined with racks of bows.",
"light" : "There is a dim light coming from above.",
"staircase" : "The only real item of notice in this room is a large spiraling staircase of onyx.",
"bones" : "Piles of bones litter the walls, decaying into dust.",
]));
set_exits(([ "out" : ROOMS "11.c",
"up" : ROOMS "outertower2.c"]));
}
void reset() {
    ::reset();
    if(!present("guard")){
        new(MOBO"towerguard")->move(this_object());
        new(MOBO"towerguard")->move(this_object());
        new(MOBO"towerguard")->move(this_object());
}
}
