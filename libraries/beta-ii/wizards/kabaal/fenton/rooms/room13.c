#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
set_property("plain",1);
    set_short("inside the city");
    set_long(
      "The city is much the same.  To your north and south are rundown "
      "houses that appear to still be occupied.  The road is beaten "
      "up, cracked, and dry. "
    );
    set_items(([
        "road" : "The road is in pretty sad shape.",
        "shacks" : "It appears as though someone still occupies them",
        "tower" : "The tower stands high in the sky.",
    ]));
   set_listen("default", "A low humming fills the area.");
   set_exits( ([ 
        "east" : ROOMS"room12.c",
        "west" : ROOMS"room14.c",
        "north" : ROOMS"en1.c",
        "south" : ROOMS"es1.c",
    ]) );
}
