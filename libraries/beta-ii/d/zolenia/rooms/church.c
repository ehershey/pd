#include <std.h>
#include <zolenia.h>
inherit ROOM;
object board;

void create() {
::create();
set_properties( ([ "light" : 2, "indoors" : 1, "cavern" : 1, "night light" : 2]) );
set_smell("default", "Throughout all of the smells of the city, an earthy smell overpowers most everything else.");
set_listen("default", "The murmurs of prayer can be heard.");
set_short("The Acadmey of Zolenia");
set_long("%^BOLD%^%^WHITE%^The church is a very quiet room, except for the prayers of the priests of Zolenia.  There are books scattering the ground on the Drow Goddess, Lloth.  There is a large statue of Lloth in the middle of the room, where priests pray.  There is a podium in the back of the room, and a pathway to the public prayer area.");
set_items(([
({"pathways", "paths"}) : "There is a pathway back to area of public prayer.",
({"air", "dust"}) : "The air is getting thinner and full of dust.",
({"book", "books"}) : "The books are quite torn up from use.",
({"statue", "statue of lloth"}) : "The statue of Lloth is made of onyx.",
({"podium"}) : "The podium seems to be where the teacher would teach.",
]));
}
void reset() {
    ::reset();
    if(!present("drowpriest")){
        new(MOB"drowpriest")->move(this_object());
        new(MOB"drowpriest")->move(this_object());
        new(MOB"drowpriest")->move(this_object());
        new(MOB"drowpriest")->move(this_object());
}
    if(!present("drowmasterpriest")){
        new(MOB"drowmasterpriest")->move(this_object());
}
set_exits(([ "out" : ROOMS "churchroad2.c",
"north" : ROOMS "church2.c"]));
}
