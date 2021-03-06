#include <std.h>
#include <zolenia.h>
inherit ROOM;
object board;

void create() {
::create();
set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2]) );
set_smell("default", "An overpowering scent of blood resonates throughout the manor.");
set_listen("default", "Moans of pleasure overpower any other sounds in this room.");
set_short("Talabune Manor");
set_long("%^BOLD%^%^YELLOW%^This entire room is full of beds surrounded by flames and covered in blood and sweat.  Next to each bed is a nightstand with drawers.  There are chains and whips hooked on to the walls.  There is an obvious female dominance in this room, with men simply being used as tools of conception.");
set_items(([
({"bed", "beds"}) : "The beds look like they get a lot of use.",
({"chains", "whips"}) : "The walls are covered in chains and whips, tools for use in pleasurably painful activities..",
({"nightstand", "drawers"}) : "The nightstand is made of a cherry oak, as are the drawers inside of it.",
]));
}
void reset() {
    ::reset();
    if(!present("talabunemother")){
        new(MOB"talabunemother")->move(this_object());
        new(MOB"talabunemother")->move(this_object());
        new(MOB"talabunemother")->move(this_object());
        new(MOB"talabunemother")->move(this_object());
        new(MOB"talabunemother")->move(this_object());
}
    if(!present("talabunemale")){
        new(MOB"talabunemale")->move(this_object());
        new(MOB"talabunemale")->move(this_object());
}
set_exits(([ "northeast" : ROOMS "50.c"]));
}
