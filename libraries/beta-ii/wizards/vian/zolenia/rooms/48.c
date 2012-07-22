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
set_long("%^BOLD%^%^BLACK%^The residential pathway south of the city leads you to the Zekyrr Manor.  In blue dragon's blood on the building is written '%^BLUE%^Dragon Rival%^BLACK%^', the meaning of the family's name.  The pathway leads back toward the city in the northeast, but there are no doors in the city of Zolenia, and the Zekyrr Manor is open.");
set_items(([
({"dirt", "path"}) : "You are walking on a dirt path going into the residential area of the city of Zolenia..  It leads either back toward the square, or to the Zekyrr Manor.",
({"air", "dust"}) : "The air is getting thinner and full of dust.",
({"house", "blood", "dragon's blood", "building", "manor"}) : "The Zekyrr Manor, a very large house here, has '%^BLUE%^Dragon Rival%^RESET%^' scrawled upon the walls.",
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
set_exits(([ "north" : ROOMS "45.c",
"enterzekyrr" : ROOMS "51.c"]));
//                             "enter zekyrr" : ROOMS "51.c"]));
//add_exit_alias("enter zekyrr", "zekyrr");
//add_exit_alias("enter zekyrr", "enter");
//add_exit_alias("enter zekyrr", "house");]));
}

