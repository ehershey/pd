
#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
set_property("plain",1);
    set_short("Fenton Slums");
    set_long(
"Here you see an old destroyed building to the east.  Above "
"your head is a sign swinging in the wind.  Looking at the "
"old, beat up road, you decide you can only go three directions.  "
"An old, dying tree rises up infront of you, stopping you from "
"venturing straight north."
    );
    set_items(([
        "building" : "The building used to be big, but is collapsed now.",
        "sign" : "Welcome to Fenton.",
        "road" : "It leads south, north west, and north east.",
        "tree" : "The tree almost seems to be glaring back at you.",
    ]));
    set_listen("default", "The sound of a rusted sign blowing in the wind.");
    set_exits( ([ 
        "south" :  ROOMS"room1.c",
        "northwest" :  ROOMS"room3.c",
        "northeast" :  ROOMS"room4.c",
    ]) );
}
