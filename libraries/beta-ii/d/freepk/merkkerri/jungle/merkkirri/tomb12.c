#include <mjungle.h>
#include <std.h>
inherit ROOM;

int searched;

void create() {
::create();
set_short("Crypt of the Fallen");
set_long("You are standing in a crypt where the ancient merkkirri buried their fallen warriors.  The Necromancers have brought many of these warriors back from the dead to serve the Merkkirri once again.");
set_items(([
({"dust", "cobwebs"}): "The catacombs are full of dust and cobwebs.",
({"stones", "floor"}): "There appears to be something stuck in the crack between two of the floor stones."]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([ "west": MJUNGLE "tomb8.c" ]));
set_smell("default", "The air is musty and stale.");
set_listen("default", "The echo of dripping water breaks the overwhelming silence.");
searched = 0;
}

void reset() {
::reset();
if(!present("warrior")) {
new(MOB "unmerk2.c")->move(this_object());
new(MOB "unmerk2.c")->move(this_object());
}
searched = 0;
}

void init() {
  ::init();
  add_action("crack_searching", "search");
}

int crack_searching(string str) {
  if(searched)
    return 0;
  if(str != "crack")
    return 0;
message("my_action", "You find a small ring that was wedged between the
stones.", this_player());
message("other_action", this_player()->query_cap_name()+" found a small ring
wedged between the floor stones.", this_object(), ({ this_player() }));
new(MOB "sapphirering.c")->move(this_object());
searched = 1;
return 1;
}
