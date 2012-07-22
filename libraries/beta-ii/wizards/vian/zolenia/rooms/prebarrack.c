#include <std.h>
#include <zolenia.h>
inherit ROOM;
object board;

void create() {
::create();
set_properties( ([ "light" : 2, "cavern" : 1, "night light" : 2]) );
set_smell("default", "Throughout all of the smells of the city, an earthy smell overpowers most everything else.");
set_listen("default", "The sounds of prayer, battle, and magical incantations echo throughout the academy.");
set_short("The Acadmey of Zolenia");
set_long("%^BOLD%^%^BLACK%^This corridor leads to the school of %^RED%^War%^BLACK%^.  The school of war takes up a small portion of the academy, with the Barracks connected to the school.  Students from the school seem to overflow out of their area into the corridor.");
set_items(([
({"pathways", "paths"}) : "The pathway leads back to the main area of the Academy.",
({"air", "dust"}) : "The air is getting thinner and full of dust.",
({"barrack", "barracks"}) : "The barracks are connected to the school of Sorcere.",
({"academy", "the academy"}) : "The academy is all around you.",
]));
}
void reset() {
    ::reset();
    if(!present("drowwarrior")){
        new(MOB"drowwarrior")->move(this_object());
        new(MOB"drowwarrior")->move(this_object());
        new(MOB"drowwarrior")->move(this_object());
}
set_exits(([ "east" : ROOMS "57.c",
"enterwar" : ROOMS "barracks.c"]));
//                             "enter war" : ROOMS "barracks.c"]));
//add_exit_alias("enter war", "enter");
//add_exit_alias("enter war", "war");
}
