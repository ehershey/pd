#include <std.h>
#include <marsh.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("indoors",1);
    set_short("Uwagi's Homes");
    set_long(
      "The hallway is an apartment complex.  At the end of the hall there is a "
       "door, the first in this town thus far.  Very little lighting is offered "
       "from the candles that are placed along sides of the hallway. "

    );
    set_items(([
        "hallway" : "A very narrow and long hallway.",
        "apartment" : "There are seven in total, each with no doors.",
        "complex" : "They are very small rooms.",
        "door" : "How odd, the only one inside the gates.",
        "lights" : "Candles.",
        "candles" : "They are barely lighting the hallway.",


    ]));
    set_exits( ([
"north" : BA "hhole17",
"south" : BA "hhole15",
"east" : BA "hhole23",
"west" : BA "hhole22",
    ]) );

}
