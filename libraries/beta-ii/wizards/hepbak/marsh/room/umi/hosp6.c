#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("building",1);
    set_short("A Mental Insitution");
    set_long(
      "%^BOLD%^%^WHITE%^This hallway, like the waiting room is very drab to look at.  Everything
"
      "%^BOLD%^%^WHITE%^is white. On either side of the hallway there is a door with a peek slot
in "
      "%^BOLD%^%^WHITE%^them. "
          );
    set_items(([
        "walls" : "No pitures on them, they are a solid white.",
        "hallway" : "It's a long hallway with doors on either side of it.",
        "door" : "They have peek hole slots in them, and they all seems to be
locked.",
        "slot" : "It is just that, you slide it open and peek in the room.",
        "peek" : "You open the slot and peek in, you see nothing.",
    ]));
    set_listen("default", "Complete silence fills the air");
    set_smell("default", "Smells of chlorine stings at your nose");
    set_exits( ([
"west" : UMI "hosp9",
"east" : UMI "hosp3",
"north" : UMI "hosp5",
"south" : UMI "hosp7",
    ]) );
}
