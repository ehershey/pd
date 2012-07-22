#include <std.h>
#include <zolenia.h>
inherit ROOM;
object board;

void create() {
::create();
set_properties( ([ "light" : 2, "cavern" : 1, "night light" : 2]) );
set_smell("default", "Throughout all of the smells of the city, an earthy smell overpowers most everything else.");
set_listen("default", "The clamor of a busy city fills your ears.");
set_short("Zolenia Trade District");
set_long("%^BOLD%^%^BLACK%^The trade district is bustling with activity.  Shadowy figures move in and out of shops quickly, not wanting to be seen.  Merchants can be seen hustling their goods in the surrounding shops, and there are many city guards here to protect them.");
set_items(([
({"dirt", "path"}) : "You are walking on a dirt path in the trade district of Zolenia.  It leads either back toward the square, or to a variety of shops.",
({"air", "dust"}) : "The air is getting thinner and full of dust.",
({"trade district", "trade"}) : "You're in the trade district.",
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
    if(!present("drowmerchant")){
        new(MOB"drowmerchant")->move(this_object());
        new(MOB"drowmerchant")->move(this_object());
        new(MOB"drowmerchant")->move(this_object());
}
set_exits(([ "out" : ROOMS "53.c",
"north" : ROOMS "weapon.c",
"east" : ROOMS "armour.c",
"northeast" : ROOMS "supply.c"]));
}
