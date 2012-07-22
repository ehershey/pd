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
set_long("%^BOLD%^%^BLACK%^The main pathway throughout the city of Zolenia is filled with clamorous activity.  A few paths stem from the main one, heading into the trade district, the academy, and the palace.  To the northeast, you can see the bustling of traders and merchants in the trade district, to the northwest you can see a large building of learning.  Straight ahead to the North is a large and magnificently constructed palace.");
set_items(([
({"dirt", "path"}) : "You are walking on a dirt path going north and south through the underground city of Zolenia..  It branches off here into three separate paths.",
({"air", "dust"}) : "The air is getting thinner and full of dust.",
({"trade", "trade district"}) : "The trade district can be seen to the northeast.",
({"academy", "the academy"}) : "To the northwest, you can see a large building of learning.",
({"palace", "castle"}) : "Straight ahead north, the entrance to a magnificent castle awaits.",
]));
}
void reset() {
    ::reset();
    if(!present("cityguard")){
        new(MOB"cityguard")->move(this_object());
        new(MOB"cityguard")->move(this_object());
}
    if(!present("drowmerchant")){
        new(MOB"drowmerchant")->move(this_object());
}
    if(!present("drowwoman")){
        new(MOB"drowwoman")->move(this_object());
}
    if(!present("drowstudent")){
        new(MOB"drowstudent")->move(this_object());
}
set_exits(([ "north" : ROOMS "52.c",
"northeast" : ROOMS "53.c",
"northwest" : ROOMS "54.c",
"south" : ROOMS "43.c"]));
}
