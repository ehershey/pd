#include <std.h>
#include <marsh.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("indoors",1);
    set_short("Uwagi's Homes");
    set_long(
      "The person who lives here, must not sleep here.  It looks to be a storage "
       "area.  There are boxes and crates everywhere stacked up from the floor "
       "to the ceiling. "

    );
    set_items(([
        "apartment" : "This one seems to be the person's storage area.",
        "area" : "There are boxes and crates everywhere.",
        "boxes" : "You know, the carboard squares you put stuff into.",
        "crates" : "It's wooden, and usually made for big stuff on the move.",
        "ceiling" : "Can't see much of it, the boxes and crates are in the way.",
        "floor" : "Not much floor space left, the room is almost jam-packed.",
        "room" : "Barely has enough room for you to stand there.",


    ]));
    set_exits( ([
"east" : BA "hhole16",

    ]) );

}
