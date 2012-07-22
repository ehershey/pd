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
      "the room.  A large, stone door covers the north wall. "
    );
    set_items(([
	"floors" : "Made of mahagony and very smooth. ",
	"statues" : "Large stone statues.",
	"door" : "A huge door that leads north is open.",
    ]));
   set_listen("default", "The humming heard before engulfs the room.");
   set_exits( ([ 
        "enter" : ROOMS"tower12.c",
        "west" : ROOMS"tower10.c",
    ]) );
}
void reset() {
::reset();
    if(!present("guardian2.c"))
      new(MOB"guardian2.c")->move(this_object());
}
