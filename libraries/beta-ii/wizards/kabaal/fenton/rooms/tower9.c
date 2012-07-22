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
      "the room.  A staircase leads down to the second floor. "
    );
    set_items(([
	"floor" : "Made of mahagony and very smooth. ",
	"staircase" : "It leads down to the second floor. ",
	"statues" : "Large stone statues.",
    ]));
   set_listen("default", "The servants talk amungst themselves.");
   set_exits( ([ 
        "down" : ROOMS"tower8.c",
        "south" : ROOMS"tower10.c",
    ]) );
}
void reset() {
::reset();
    if(!present("servant.c"))
      new(MOB"servant.c")->move(this_object());
      new(MOB"servant.c")->move(this_object());
      new(MOB"servant.c")->move(this_object());
      new(MOB"servant.c")->move(this_object());
      new(MOB"servant.c")->move(this_object());
}
