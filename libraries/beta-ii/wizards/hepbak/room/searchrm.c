#include <std.h>
#include <wildflower.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("forest",1);
    set_short("Outdoor room");
    set_day_long(
      "There are birds chirping in the trees.  "

    );

    set_night_long(
      "Evil red eyes glowing in the night."
    );
    set_items(([
        "room" : "a room.",
    ]));
    set_smell("default", "It smells of outdoors..");
    set_listen("default", "Sounds like a forest");
    set_exits( ([
"west" :  ROOMS "outdoor",
"north" : ROOMS "outdoor2",
    ]) );

}
void init(){
    ::init();
    add_action("search", "search");
}
int search(string str) {
    write("A hole is under some leaves.\n");
    add_exit( ROOMS "outdoor3" , "hole");
    return 1;
}

