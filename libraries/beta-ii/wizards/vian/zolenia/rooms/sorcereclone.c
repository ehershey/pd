#include <std.h>
#include <zolenia.h>
inherit ROOM;
object board;

void create() {
::create();
set_properties( ([ "light" : 2, "cavern" : 1, "night light" : 2]) );
set_smell("default", "Throughout all of the smells of the city, an earthy smell overpowers most everything else.");
set_listen("default", "There is no sound except for quiet incantations.");
set_short("The Acadmey of Zolenia");
set_long("%^BOLD%^%^BLACK%^The school of %^BLUE%^sorcere %^BLACK%^is a very quiet, small room.  There are many random magical items simply floating in mid air, and the entire room is lit by a magical orb floating on top of the ceiling.  There are books on the art of the sorcerer scattered around the ground.  There is a podium in the back of the room.");
set_items(([
({"pathways", "paths"}) : "There is a pathway back to the main area of the Academy.",
({"air", "dust"}) : "The air is getting thinner and full of dust.",
({"book", "books"}) : "The books are quite torn up from use.",
({"orb", "ceiling", "magical orb"}) : "The large, glowing magical orb floating on the top of the ceiling lights up the entire room.",
({"magical items", "items"}) : "There are many magical items simply floating around in mid air.",
({"podium"}) : "The podium seems to be where the teacher would teach.",
]));
}
void reset() {
    ::reset();
    if(!present("drowsorcerer")){
        new(MOB"drowsorcerer")->move(this_object());
        new(MOB"drowsorcerer")->move(this_object());
        new(MOB"drowsorcerer")->move(this_object());
        new(MOB"drowsorcerer")->move(this_object());
}
    if(!present("drowmastersorcerer")){
        new(MOB"drowmastersorcerer")->move(this_object());
}
    if(!present("portalclone")){
        new(OBJ"portalclone")->move(this_object());
}
    if (!present("deed")){
        new(OBJ "deed")->move(this_object());
}
set_exits(([ "out" : ROOMS "57clone"]));
set_pre_exit_functions(({"out"}), ({"check_oo"}));
}
void init() {
  ::init();
   if (this_player()->query_riding()) {
   write("%^BOLD%^%^BLUE%^The dragon yells: %^RESET%^%^BOLD%^<say Go> if you think I can make it!%^RESET%^");
 }
}
int check_oo() {
    if(this_player()->query_race() != "borg") {
        write("You cannot pass on the large dragon.");
        return 0;
    }
    write("You pass through with ease.");
    return 1;
}
