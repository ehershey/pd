#include <std.h>
#include <marsh.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("indoors",1);
    set_short("Uwagi's Apartment");
    set_long(
      "This apartment is all beat up.  The wall, even though it is made of dirt, "
      "looks to have holes punched in them.  The bed has broken boards, and the "
      "stuffing is falling out.  Who ever lives here, is quite violent. "

    );
    set_items(([
        "room" : "A little small, but not claustrophobic.",
        "bed" : "The head-board is all broken and the matress is falling apart.",
        "apartment" : "It is all beat up.",
        "holes" : "There is many of them all over the walls.",
        "stuffing" : "It's falling out of the matress and on to the floor.",
        "dirt" : "It's smoothed out after the digging was compleated.",
        "boards" : "Yup, they are broken.",
    
    ]));
    set_exits( ([
"east" : BA "hhole14",
    ]) );

}
