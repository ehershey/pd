#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 0, "indoors" : 1]) );
set_property("cave",1);
    set_short("inside a dark cave");
    set_long(
      "Inside the cave, the temperature is quite comfortable.  The stone walls "
      "are drawn to your attention.  They harbor strange markings that look ancient. ");
    set_items(([
        "markings" : "Ancient symbols that you can't make out the meaning of.",
        "walls" : "The walls have strange markings on them.",
    ]));
   set_exits( ([ 
        "north" : ROOMS"cave9.c",
        "west" : ROOMS"cave7.c",
    ]) );
}
void reset() {
::reset();
    if(!present("zombie.c"))
      new(MOB"zombie.c")->move(this_object());
      new(MOB"zombie.c")->move(this_object());
      new(MOB"zombie.c")->move(this_object());
      new(MOB"zombie.c")->move(this_object());
}
