#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
set_property("building",1);
    set_short("a old rotting house");
    set_long(
      "Another run down house with peeling walls, falling ceiling, and a dirt floor.  A "
      "dead houseplant sits in a corner, while a small chair sits in another.  The room is "
      "simple and underkept. "
    );
    set_items(([
        "ceiling" : "Whoever made this should be shot.",
        "walls" : "The walls peel from age and neglect.",
	"floor" : "Worn down dirt.",
	"chair" : "It looks quite uncomfortable and appears to have been made in 10 minutes.",
	"houseplant" : "Like much of the rest of the city, it is dead.",
    ]));
   set_exits( ([ 
        "north" : ROOMS"room14.c",
    ]) );
}
void reset() {
::reset();
    if(!present("mom.c"))
      new(MOB"mom.c")->move(this_object());
      new(MOB"girl.c")->move(this_object());
}
