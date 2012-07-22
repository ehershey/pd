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
({"walls"}) : "The walls are what you are currently walking on.",
({"onyx", "ground"}) : "The ground is lined with sleek onyx, shining brightly against an undetermined source of light.",
"groves" : "The railing of the walls groves in naturally.",
({"bows", "arrows"}) : "Fresh cut bows and arrows are kept in the natural groves of the walls.",
"railing" : "The railing of the walls groves in naturally.",
"guards" : "On the inside of the gate, there are guards to be seen below.",
]));
set_exits(([ "south" : ROOMS "36.c",
"north" : ROOMS "34.c"]));
}
void reset() {
    ::reset();
    if(!present("wallarcher")){
        new(MOB"wallarcher")->move(this_object());
        new(MOB"wallarcher")->move(this_object());
        new(MOB"wallarcher")->move(this_object());
}
}
