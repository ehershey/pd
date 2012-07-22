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
set_long("%^BOLD%^%^BLACK%^The trade district can be seen from here, bustling with merchant life and shops.  Tents line the path with vendors who are working on selling their goods.  There are armour shops, weapon shops, and magic shops, specializing in the great magical Drow items.");
set_items(([
({"dirt", "path"}) : "You are walking on a dirt path going into the residential area of the city of Zolenia..  It leads either back toward the square, or to the city's trade district.",
({"air", "dust"}) : "The air is getting thinner and full of dust.",
({"trade district", "trade"}) : "The trade district is straight to the northeast.",
({"tents"}) : "There are tents lining the path of merchants working on selling their goods.",
]));
}
void reset() {
    ::reset();
    if(!present("cityguard")){
        new(MOB"cityguard")->move(this_object());
        new(MOB"cityguard")->move(this_object());
}
    if(!present("drowwoman")){
        new(MOB"drowwoman")->move(this_object());
}
    if(!present("drowmerchant")){
        new(MOB"drowmerchant")->move(this_object());
}
set_exits(([ "southwest" : ROOMS "44.c",
"entertrade" : ROOMS "56.c"]));
//                             "enter trade district" : ROOMS "56.c"]));
//add_exit_alias("enter trade district", "enter");
//add_exit_alias("enter trade district", "trade");
//add_exit_alias("enter trade district", "district");
//add_exit_alias("enter trade district", "trade district");
}
