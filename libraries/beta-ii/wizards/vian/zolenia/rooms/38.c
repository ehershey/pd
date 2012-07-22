#include <std.h>
#include <zolenia.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "cavern" : 1, "night light" : 1]) );
set_smell("default", "The smell of fresh cut arrows overpowers the top of the walls.");
set_listen("default", "The stringing of bows chimes throughout the room.");
set_short("on top of the gate walls");
set_long("The top of the gate's walls are fairly straightforward and bland.  Although there is a lack of variation, there is still an attractiveness present here.  Sleek onyx lines the ground, growing tall to fence off the ledge.  Natural groves in the railing provide storage space for bows and arrows.  Gate guards can be seen below.");
set_items(([
({"onyx", "path"}) : "The top of the walls seems to be a square sort of path around the city.",
({"wood", "footprints"}) : "Dusty bits of woodchips cover the path, and footprints can be seen.",
"ground" : "The ground is covered in bits of woodchips.",
({"air", "dust"}) : "Particles of dust can be seen floating throughout the air.",
"gate" : "Yep, you're on top of it.",
"ladder" : "Scratched into the onyx wall beside the gate door, and definitely not the safest climb, it seems like it's scarier going back down.",
"shadows" : "The darkness makes for no shadows, although a presence can be felt.",
]));
set_exits(([ "east" : ROOMS "39.c",
"west" : ROOMS "37.c"]));
}
void reset() {
    ::reset();
    if(!present("wallarcher")){
        new(MOB"wallarcher")->move(this_object());
        new(MOB"wallarcher")->move(this_object());
        new(MOB"wallarcher")->move(this_object());
}
}
