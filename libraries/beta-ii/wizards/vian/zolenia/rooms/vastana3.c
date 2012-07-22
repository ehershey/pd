#include <std.h>
#include <zolenia.h>
inherit ROOM;
object board;

void create() {
::create();
set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2]) );
set_smell("default", "An overpowering scent of blood resonates throughout the manor.");
set_listen("default", "Moans of pleasure overpower any other sounds in this room.");
set_short("Vastana Manor");
set_long("%^BOLD%^%^RED%^This entire room is full of beds covered in blood and sweat.  Next to each bed is a nightstand with drawers.  There are chains and whips hooked on to the walls.  There is an obvious female dominance in this room, with men simply being used as tools of conception.");
set_items(([
({"bed", "beds"}) : "The beds look like they get a lot of use.",
({"chains", "whips"}) : "The walls are covered in chains and whips, tools for use in pleasurably painful activities..",
({"nightstand", "drawers"}) : "The nightstand is made of a cherry oak, as are the drawers inside of it.",
]));
}
void reset() {
    ::reset();
    if(!present("vastanamother")){
        new(MOB"vastanamother")->move(this_object());
        new(MOB"vastanamother")->move(this_object());
        new(MOB"vastanamother")->move(this_object());
        new(MOB"vastanamother")->move(this_object());
        new(MOB"vastanamother")->move(this_object());
}
    if(!present("vastanamale")){
        new(MOB"vastanamale")->move(this_object());
        new(MOB"vastanamale")->move(this_object());
}
set_exits(([ "northeast" : ROOMS "49.c"]));
}
