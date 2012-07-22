#include <std.h>
#include <marsh.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("indoors",1);
    set_short("Uwagi's Apartment");
    set_long(
      "This is an one room apartment, there is a bed off in the corner and a "
      "small closet next to it.  It has a desk by one wall with papers scattered "
      "everywhere. "

    );
    set_items(([
        "room" : "Quite roomy for a one room area.",
        "corner" : "Has a huge bed there.",
        "apartment" : "It is a one room area, but not claustrophobic.",
        "bed" : "A nice big bed with fluffy pillows on top.",
        "pillows" : "Four to be exact, and they look to be made of feathers.",
        "desk" : "A wooden desk, with papers scattered about and lamp.",
        "closet" : "There is a dresser inside and clothes hanging up.",
        "papers" : "Nothing special, just making a mess on the desk.",
        "dresser" : "A little messy, some clothes are stuck in the drawers.",
        "clothes" : "Lizard-people style clothes.",
        "lamp" : "A small lamp, the only thing that lights up the room.",


    ]));
    set_exits( ([
"west" : BA "hhole14",
    ]) );

}
