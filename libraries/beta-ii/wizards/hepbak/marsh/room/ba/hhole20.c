#include <std.h>
#include <marsh.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("indoors",1);
    set_short("Uwagi's Homes");
    set_long(
       "This room looks very prissy.  There is a silver vanity with a "
       "red velvet chair placed in front of it.  The bed is full of lace, "
       "almost looks like it's never been slept in.  There are lots of "
       "stuff animals everywhere!"
    );
    set_items(([
        "room" : "It gives you shivers how girlish this room looks.",
        "vanity" : "Its a desk that holds make-up and has a mirror behind it.",
        "mirror" : "Has little lights around it.",
        "lights" : "Small ones that light up one's face.",
        "chair" : "It is made of red velvet, and is placed in front of the vanity.",
        "bed" : "It seems to have layers and layers of lace.",
        "lace" : "Looks homemade.",
        "animals" : "All sorts of different animals placed all over the room.",


    ]));
    set_exits( ([
"east" : BA "hhole15",
    ]) );

}
