#include <std.h>
#include <zolenia.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2]) );
set_smell("default", "The smell of freshly cut wood fills the tower.");
set_listen("default", "The sound of arrows hitting practice targets and the cutting of arrows echoes throughout the tower.");
set_short("an archer's tower");
set_long("The top of the tower has no walls, simply railings which are lined with buckets full of arrows.  There are posts separating areas where archers should be standing.  The posts have racks of bows attached to them.  There is an orb of light floating in the center of the room.  The staircase spirals back down to the ground level of the tower.");
set_items(([
"walls" : "There are no walls in this room, simply openings for the archers to shoot from.",
"buckets" : "There are buckets full of arrows lining the walls.",
"posts" : "There are posts which seem to be all there is for walls.",
"steps" : "The steps are very large.",
({"racks", "rack", "bows"}) : "The posts have racks of bows attached to them.",
"light" : "There is an orb of light floating in the middle of the room.",
"orb" : "There is an orb of light floating in the middle of the room.",
"staircase" : "The staircase is crafted from onyx, with large steps going downwards.",
]));
set_exits(([ "down" : ROOMS "outertower.c",]));
}
void reset() {
    ::reset();
    if(!present("archer")){
        new(MOBO"towerarcher")->move(this_object());
        new(MOBO"towerarcher")->move(this_object());
        new(MOBO"towerarcher")->move(this_object());
}
}
