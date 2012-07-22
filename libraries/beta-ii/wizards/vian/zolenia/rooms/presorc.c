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
set_long("%^BOLD%^%^BLACK%^This corridor leads to the school of %^BLUE%^Sorcere%^BLACK%^.  The school appears to take up most of the academy, as the drow mind has inclined them to study the art of Sorcere.  Students from the school seem to overflow out of their area into the corridor.");
set_items(([
({"pathways", "paths"}) : "The pathway leads back to the main area of the Academy.",
({"air", "dust"}) : "The air is getting thinner and full of dust.",
({"academy", "the academy"}) : "The academy is all around you.",
]));
}
void reset() {
    ::reset();
    if(!present("drowstudent")){
        new(MOB"drowstudent")->move(this_object());
        new(MOB"drowstudent")->move(this_object());
        new(MOB"drowstudent")->move(this_object());
        new(MOB"drowstudent")->move(this_object());
        new(MOB"drowstudent")->move(this_object());
}
set_exits(([ "south" : ROOMS "57.c",
"entersorcere" : ROOMS "sorcere.c"]));
//                             "enter sorcere" : ROOMS "sorcere.c"]));
//add_exit_alias("enter sorcere", "enter");
//add_exit_alias("enter sorcere", "sorcere");
}
