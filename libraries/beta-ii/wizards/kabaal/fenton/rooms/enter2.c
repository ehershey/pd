#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 3, "indoors" : 1]) );
set_property("building",1);
    set_short("rundown kitchen");
    set_long(
      "A beat up room, this kitchen doesn't appear to be in the best of shape.  The walls are "
      "covered in dirt and grime, the once tiled floor is coming apart, and the only window has "
      "shattered.  The table in this room is made of cedar.  There is an empty ceramic pot in the corner. "
    );
    set_items(([
        "window" : "It has been shattered.  The giant rock on the ground looks like it was chucked in.",
        "table" : "It is bare and made of cedar.",
        "pot" : "It's empty.",
        "floor" : "Its tiles are being torn up from years of being walked on.",
        "walls" : "Yep, dirty, huh?.",
    ]));
   set_listen("default", "Rats and other small rodents scurry across the floor.");
   set_exits( ([ 
        "west" : ROOMS"enter1.c",
    ]) );
}
