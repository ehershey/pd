#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("swamp",1);
    set_short("Elephant's Graveyard");
    set_day_long(
      "The bones here are stacked up in piles. Rather unusual, no other "
      "spot of the Elephant's Graveyard looks like this. "
    );
    set_night_long(
      "The bones here are stacked up in piles. Rather unusual, no other "
      "spot of the Elephant's Graveyard looks like this. "
    );
    set_items(([
        "bones" : "There seems to something behind the bone piles.",
        "graveyard" : "There are bones scattered everywhere.",
    ]));
    set_smell("default", "It smells like rotting flesh.");
    set_listen("default", "Echoes of howling is loud here");
    set_exits( ([
"north" : ELE "ele9",
    ]) );
}
void init(){
    ::init();
    add_action("search", "search");
}
int search(string str) {
    write("A hole is under some bones.\n");
    add_exit(ELE "tunnel", "hole");
    return 1;
}
