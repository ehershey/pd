#include <std.h>
#include <zolenia.h>
inherit ROOM;
object board;
void create() {
::create();
set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2]) );
set_smell("default", "The smell of dragon's blood fills the area.");
set_listen("default", "Roars of pained dragons can be heard throughout the manor.");
set_short("Zekyrr Manor");
set_long("%^BOLD%^%^BLUE%^The Zekyrr torture room is also a classroom, where the Matron Mother teaches the children of Zekyrr the ways of torturing a dragon.  There are weapons and torture tools littering the floor, scattered alongside random dragon appendages.  There is a grate in the corner of the room, with dragon blood dripping down into it, and a path leading back into the main room of the house.");
set_items(([
({"paths", "path"}) : "There is a path leading back into the main room of the house.",
({"tools", "weapons", "appendages"}) : "The floor is littered with weapons, torture tools, and random dragon appendages.",
"grate" : "There is a grate in the corner of the room, with dragon blood dripping down into it..",
"classroom" : "The room is a sort of classroom of torture..",
"blood" : "The dragon blood is silvery and thick.",
]));
}
void reset() {
    ::reset();
    if(!present("zekyrrmatronmother")){
        new(MOB"zekyrrmatronmother")->move(this_object());
}
    if(!present("zekyrrdragon")){
        new(MOB"zekyrrdragon")->move(this_object());
}
    if(!present("zekyrrchild")){
        new(MOB"zekyrrchild")->move(this_object());
        new(MOB"zekyrrchild")->move(this_object());
        new(MOB"zekyrrchild")->move(this_object());
}
set_exits(([ "northwest" : ROOMS "51.c",
"grate" : ROOMS "zekyrr4.c"]));
}
