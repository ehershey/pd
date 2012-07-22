#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
    set_short("Fenton City Limits");
    set_long(
      "There is a poor looking city to the north.  It looks "
      "as though it used to be prosperous, but now it is known "
      "as the Fenton Slums.  Crime and corruption rule the city "
      "and some have entered and never returned."
    );
    set_items(([
        "city" : "The city looks old and worthless.",
        "slums" : "Crime and corruption rule this once great city.",
    ]));
   set_listen("default", "The occasional innocent scream can be heard.");
   set_exits( ([ 
        "north" : ROOMS"room2.c",
        "south" : ROOMS"hidden3.c",
    ]) );
}
