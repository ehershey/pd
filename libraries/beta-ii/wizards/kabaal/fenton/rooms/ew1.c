#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
set_property("building",1);
    set_short("a nice house");
    set_long(
      "This is the bedroom of the house.  There are two beds that appear long and comfortable. "
      "A mirror rests on the western wall, and a window overlooks on the northern wall.  A rocking "
      "chair occupies a corner of the house. "
    );
    set_items(([
        "mirror" : "You about faint from the appearance of the hideous being in the mirror.",
        "window" : "It outlooks the Forest of Saltor.",
	"beds" : "They look mighty comfy.",
	"chair" : "It sits in the corner quitely.",
    ]));
   set_exits( ([ 
        "east" : ROOMS"en2.c",
    ]) );
}
void reset() {
::reset();
    if(!present("lep.c"))
      new(MOB"lep.c")->move(this_object());
}
