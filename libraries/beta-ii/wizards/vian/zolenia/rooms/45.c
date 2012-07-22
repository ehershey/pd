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
set_long("%^BOLD%^%^BLACK%^The main pathway throughout the city of Zolenia is filled with clamorous activity.  A few paths stem from the main one, heading into the residential district of the city.  The houses in the distance can be seen from here, not small buildings but huge manors in which entire drow families live.");
set_items(([
({"dirt", "path"}) : "You are walking on a dirt path going north and south through the underground city of Zolenia..  It branches off here into three separate paths.",
({"air", "dust"}) : "The air is getting thinner and full of dust.",
({"house", "manor", "manors", "houses"}) : "The houses are giant buildings crafted of onyx, with different specialties to each of them.",
]));
}
void reset() {
    ::reset();
    if(!present("cityguard")){
        new(MOB"cityguard")->move(this_object());
        new(MOB"cityguard")->move(this_object());
}
    if(!present("beggar")){
        new(MOB"beggar")->move(this_object());
}
    if(!present("drowwoman")){
        new(MOB"drowwoman")->move(this_object());
}
    if(!present("drowchild")){
        new(MOB"drowchild")->move(this_object());
}
set_exits(([ "north" : ROOMS "43.c",
"southeast" : ROOMS "46.c",
"southwest" : ROOMS "47.c",
"south" : ROOMS "48.c"]));
}
