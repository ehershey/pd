#include <std.h>
#include <marsh.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("inside",1);
    set_short("Bedroom of of home");
    set_long(
      "In here is a bedroom, a chandelier hangs above the bed, which is sitting in the middle "
      "of the room.  There is a dresser with a mirror by a wall."

          );

    
    set_items(([
        "bedroom" : "Very roomy looking.",
        "dresser" : "It is made of gold, with a gold mirror attached to it.",
        "bed" : "The bed post are made of gold, and the bedding is pure silk.",
        "chandelier" : "Made with real diamonds and real gold.",

    ]));

    set_exits( ([
"south" : BA "hhole3",
    ]) );

}
