

#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 0, "indoors" : 1]) );
set_property("building",1);
    set_short("inside the city");
    set_long(
      "This drab house appears to be a few hundered years of age.  "
      "The walls are cracked, the dirt floor is dry, pieces of the "
      "ceiling are falling.  The family that owns this one room house "
      "doesn't obviously need it for a whole lot. "
    );
    set_items(([
        "floor" : "The dirt floor is dry and well worn.",
        "walls" : "The walls have many long cracks running down them",
        "ceiling" : "The ceiling has missing parts and parts hanging from it.",
    ]));
   set_exits( ([ 
        "north" : ROOMS"room13.c",
    ]) );
}
void reset() {
::reset();
    if(!present("skboy.c"))
      new(MOB"skboy.c")->move(this_object());
      new(MOB"skfather.c")->move(this_object());
      new(MOB"skmother.c")->move(this_object());
}
