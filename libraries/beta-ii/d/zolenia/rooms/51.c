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
set_long("%^BOLD%^%^BLUE%^The Zekyrr manor appears through the largest entranceway in all of Zolenia, large enough for even the fattest dragon.  The walls are covered in black dragonscales, and there are dragon claws and tailspikes mounted amongst the walls as decorations.  There are pathways leading to different rooms in the house.");
set_items(([
({"paths", "pathways", "path"}) : "Multiple paths lead to different rooms in the house.",
({"claws", "tailspikes"}) : "The walls are covered in mounted decorations of claws and tailspikes.",
"dragonscales" : "The walls of the Zekyrr manor are covered in dragonscales..",
"entranceway" : "The entranceway to the Zekyrr manor is huge, large enough for the fattest dragon.",
]));
}
void reset() {
    ::reset();
    if(!present("zekyrrmother")){
        new(MOB"zekyrrmother")->move(this_object());
}
    if(!present("zekyrrmale")){
        new(MOB"zekyrrmale")->move(this_object());
}
    if(!present("zekyrrchild")){
        new(MOB"zekyrrchild")->move(this_object());
        new(MOB"zekyrrchild")->move(this_object());
        new(MOB"zekyrrchild")->move(this_object());
}
set_exits(([ "southeast" : ROOMS "zekyrr2.c",
"out" : ROOMS "48.c",
"southwest" : ROOMS "zekyrr3.c"]));
}
