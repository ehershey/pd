#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
set_property("building",1);
    set_short("inside darkness");
    set_long(
      "A small, broken stained glass window is placed on the southern wall "
      "outlooking the dark alley.  Four beds are here, with a small chest at "
      "the base of each.  A portrait of a mysterious mage hangs above a bed. "
    );
    set_items(([
        "window" : "It is broken, however after looking at it, it appears to be a cross.",
        "stained glass" : "It is broken, however after looking at it, it appears to be a cross.",
        "portrait" : "A wise looking man smoking a pipe.  He has an evil grin spread upon his face.",
    ]));
   set_listen("default", "A baby's crying floats throughout the room.");
   set_exits( ([ 
        "down" : ROOMS"enter1.c",
    ]) );
}
void reset() {
::reset();
    if(!present("bwidow.c"))
      new(MOB"bwidow.c")->move(this_object());
      new(MOB"bat.c")->move(this_object());
}
