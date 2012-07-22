#include <std.h>
#include <zolenia.h>
inherit ROOM;
object board;

void create() {
::create();
set_properties( ([ "light" : 2, "cavern" : 1, "night light" : 2, "no teleport" : 1]) );
set_smell("default", "Throughout all of the smells of the city, an earthy smell overpowers most everything else.");
set_listen("default", "The sounds of prayer, battle, and magical incantations echo throughout the academy.");
set_short("The Acadmey of Zolenia");
set_long("%^BOLD%^%^BLACK%^The academy is full of students of all sorts of arts.  There are two different pathways to the different areas, the school of %^BLUE%^Sorcere%^BLACK%^ and the school of %^RED%^War%^BLACK%^.  Students from the School of %^BLUE%^Sorcere%^BLACK%^ seem to overflow out of their area into the common area of the academy.");
set_items(([
({"pathways", "paths"}) : "There are two different pathways, to the school of Sorcere, and the school of War.",
({"air", "dust"}) : "The air is getting thinner and full of dust.",
({"academy", "the academy"}) : "The academy is all around you..",
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
set_exits(([ "out" : ROOMS "54clone.c",
"north" : ROOMS "presorcclone.c",
"west" : ROOMS "prebarrack.c"]));
set_pre_exit_functions(({"out"}), ({"check_oo"}));
set_pre_exit_functions(({"west"}), ({"check_eb"}));
}
int check_oo() {
    if(this_player()->query_race() != "borg") {
        write("You cannot pass on the large dragon.");
        return 0;
    }
    write("You pass through with ease.");
    return 1;
}
int check_eb() {
    if(this_player()->query_race() != "borg") {
        write("You cannot pass on the large dragon.");
        return 0;
    }
    write("You pass through with ease.");
    return 1;
}
