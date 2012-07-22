#include <std.h>
#include <zolenia.h>
inherit ROOM;
object board;

void create() {
::create();
set_properties( ([ "light" : 2, "cavern" : 1, "night light" : 2]) );
set_smell("default", "Throughout all of the smells of the city, an earthy smell overpowers most everything else.");
set_listen("default", "The clamor of a busy city fills your ears.");
set_short("Zolenia city path");
set_long("%^BOLD%^%^BLACK%^The residential pathway south of the city leads you to the Vastana Manor.  On the building, in blood, is written '%^RED%^Blood of Darkness%^BLACK%^', the meaning of the family's name.  The pathway leads back toward the city in the northwest, but there are no doors in the city of Zolenia, and the Vastana Manor is open.");
set_items(([
({"dirt", "path"}) : "You are walking on a dirt path going into the residential area of the city of Zolenia..  It leads either back toward the square, or to the Vastana Manor.",
({"air", "dust"}) : "The air is getting thinner and full of dust.",
({"house", "building", "blood", "manor"}) : "The Vastana Manor, a very large house here, has '%^RED%^Blood of Darkness%^RESET%^' scrawled upon the walls.",
]));
}
void reset() {
    ::reset();
    if(!present("cityguard")){
        new(MOB"cityguard")->move(this_object());
}
    if(!present("drowwoman")){
        new(MOB"drowwoman")->move(this_object());
}
    if(!present("drowchild")){
        new(MOB"drowchild")->move(this_object());
}
set_exits(([ "northwest" : ROOMS "45.c",
"entervastana" : ROOMS "49.c",]));
//                             "enter vastana" : ROOMS "49.c"]));
//add_exit_alias("enter vastana", "vastana");
//add_exit_alias("enter vastana", "enter");
//add_exit_alias("enter vastana", "house");
}
