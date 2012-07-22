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
set_long("%^BOLD%^%^WHITE%^The church's public prayer area is not as nice as the priest's teaching area, but is still nicer than most of Zolenia.  There is a large statue of Lloth in the middle of the room, where families come to pray.  There are paintings of the Valsharess and Lloth covering the walls.");
set_items(([
({"pathways", "paths"}) : "There is a pathway back to church.",
({"painting", "paintings"}) : "The paintings of the Valsharess and Lloth are very intricate, definitely works that took a long time.",
({"statue", "statue of lloth"}) : "The statue of Lloth is made of onyx.",
]));
}
void reset() {
    ::reset();
    if(!present("drowpriest")){
        new(MOB"drowpriest")->move(this_object());
        new(MOB"drowpriest")->move(this_object());
}
    if(!present("drowwoman")){
        new(MOB"drowwoman")->move(this_object());
        new(MOB"drowwoman")->move(this_object());
}
set_exits(([ "south" : ROOMS "church.c"]));}
