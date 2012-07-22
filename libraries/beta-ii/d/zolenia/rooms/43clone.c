#include <std.h>
#include <zolenia.h>
inherit ROOM;
object board;

void create() {
::create();
set_properties( ([ "no attack" : 1, "no magic" : 1, "no bump" : 1, "no steal" : 1, "light" : 2, "indoors" : 1, "cavern" : 1, "night light" : 2]) );
set_smell("default", "Throughout all of the smells of the city, an earthy smell overpowers most everything else.");
set_listen("default", "The clamor of a busy city fills your ears.");
set_short("Zolenia city square");
set_long("%^BOLD%^%^BLACK%^The city square of Zolenia is filled with clamorous activity.  There is a large fountain in the center of the square, bubbling with %^GREEN%^acid %^BLACK%^and hosting a large statue.  A bulletin board has been placed on the side of the fountain.  There is a rope leading back up the tunnel.");
set_exits(([ "north" : ROOMS "44clone.c",
 "west" : ROOMS "churchroad.c",
 "up" : ROOMS "42.c",
"south" : ROOMS "45.c"]));
set_pre_exit_functions(({"south"}), ({"check_ss"}));
set_pre_exit_functions(({"west"}), ({"check_ww"}));
set_pre_exit_functions(({"up"}), ({"check_uu"}));
set_items(([
({"dirt", "path"}) : "The square is in the center of a dirt path going north and south through the underground city of Zolenia..",
({"air", "dust"}) : "The air is getting thinner and full of dust.",
]));
    board = new("std/bboard");
    board->set_name("zoleniasquare");
    board->set_id( ({ "board", "zolenia board" }) );
    board->set_max_posts(500);
board->set_edit_ok(({"stormbringer","nulvect","luna","whit","amun","daos","ironman","pyro","randalar","leondal","vian"}));
    board->set_location(ROOMS "43clone");
    board->set("short", "%^BOLD%^%^BLACK%^Zolenia Board%^RESET%^");
    board->set("long", "A tattered and unkept board in the center of the Drow City.\n");
    board->set_board_id("zoleniasquare");
}
void reset() {
    ::reset();
        if(!present("statue"))
          new(OBJ "statue")->move(this_object());
        if (!present("fountain"))
          new(OBJ "fountain")->move(this_object());
    if(!present("cityguard")){
        new(MOB"cityguard")->move(this_object());
        new(MOB"cityguard")->move(this_object());
        new(MOB"cityguard")->move(this_object());
}
}
int check_ss() {
    if(this_player()->query_race() != "borg") {
        write("You cannot pass on the large dragon.");
        return 0;
    }
    write("You pass through with ease.");
    return 1;
}
int check_ww() {
    if(this_player()->query_race() != "borg") {
        write("You cannot pass on the large dragon.");
        return 0;
    }
    write("You pass through with ease.");
    return 1;
}
int check_uu() {
    if(this_player()->query_race() != "borg") {
        write("You cannot pass on the large dragon.");
        return 0;
    }
    write("You pass through with ease.");
    return 1;
}
