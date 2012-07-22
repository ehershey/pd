#include <std.h>
#include <zolenia.h>
inherit ROOM;
object board;
void create() {
::create();
set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2]) );
set_smell("default", "The smell of dragon's blood fills the area.");
set_listen("default", "Dragon's painful grunts echo throughout the walls of this small sewer.");
set_short("Zekyrr Sewer");
set_long("%^BOLD%^%^BLACK%^The grate leads to a small sewer area, full of dragon's blood.  The stones here are not smooth onyx, but coarse stone, and the temperature is even colder than the Drow city.  Things scurry around these rooms so quickly, it's impossible to tell what they are.  There is a breeze coming through, although it's starting point is unknown.");
set_items(([
({"stone", "onyx", "coarse stone", "stones"}) : "The coarse stone is as far from onyx as it gets, very scratchy and unpleasant to touch.",
({"blood", "dragons blood", "dragon's blood"}) : "The dragons blood is silvery and thick.",
"grate" : "There is a grate to get back to the Zekyrr manor.",
"breeze" : "Ah, if only you could see air..",
"things" : "These things are scurrying so quickly, you can't even tell what they are at first glance!",
]));
}
void reset() {
    ::reset();
    if(!present("escapee1")){
        new(MOB"escapee1")->move(this_object());
}
    if(!present("dirtyrat")){
        new(MOB"dirtyrat")->move(this_object());
        new(MOB"dirtyrat")->move(this_object());
        new(MOB"dirtyrat")->move(this_object());
}
set_exits(([ "north" : ROOMS "z4n.c",
"east" : ROOMS "z4e.c",
"south" : ROOMS "z4s.c",
"west" : ROOMS "z4w.c",
"grate" : ROOMS "zekyrr2.c"]));
set_pre_exit_functions(({"grate"}), ({"check_grate"}));
}
int check_grate() {
    if(this_player()->query_riding()) {
        this_player()->move_player(ROOMS "zekyrr2clone");
        say(this_player()->query_cap_name()+" rides north.");
        return 0;
    }
    return 1;
}
