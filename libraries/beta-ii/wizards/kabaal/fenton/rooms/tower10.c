#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
set_property("building",1);
    set_short("servants quarters");
    set_long(
      "The servants quarters are nicely decorated.  The floor is a smooth "
      "mahagony and statues lie about the room.  Nice furnishings decorate "
      "the room. "
    );
    set_items(([
	"floor" : "Made of mahagony and very smooth. ",
	"statues" : "Large stone statues.",
    ]));
   set_listen("default", "The servants talk amungst themselves.");
   set_exits( ([ 
        "north" : ROOMS"tower9.c",
        "east" : ROOMS"tower11.c",
    ]) );
}
void reset() {
::reset();
    if(!present("servant.c"))
      new(MOB"servant.c")->move(this_object());
      new(MOB"servant.c")->move(this_object());
      new(MOB"servant.c")->move(this_object());
}

