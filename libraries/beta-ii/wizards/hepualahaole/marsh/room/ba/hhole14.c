#include <std.h>
#include <marsh.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("indoors",1);
    set_short("Uwagi's Homes");
    set_long(
      "This is the entrance to a rather long hallway.  It seems that this is an "
      "apartment complex.  At the end of the hall there is a door, the first in "
      "this town thus far.  Very little light is offered from the candles "
      "that are placed along sides of the hallway. "

    );
    set_items(([
        "entrance" : "The entrance leads into a big hallway.",
        "hallway" : "It is long and narrow, with candles hanging along the sides
.",
        "apartment" : "A total of seven of them off to the sides and north of he
re.",
        "complex" : "They are very small rooms.",
        "door" : "How odd, the only one inside the gates.",
        "lights" : "Candles.",
        "candles" : "They are barely lighting the hallway.",


    ]));
    set_exits( ([
"north" : BA "hhole15",
"out" : BA "ba32",
"east" : BA "hhole19",
"west" : BA "hhole18",
    ]) );

}
