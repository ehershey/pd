#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
    set_short("A cottages backyard");
    set_long(
      "This is the backyard of the old cottage. An outhouse sits "
      "in the middle of the yard. The grass is growing wildly except "
      "for the path to the outhouse. The forest surrounds the backyard "
      "preventing one from leaving in any direction except from which they "
      "came. The back of the cottage is rather small."
    );
    set_items(([
   "window" : "The window is open, making for a nice breeze filling the room. ",
   "path" : "A path from the outhouse to the open window. Another small path goes "
	    "off into the forest. Maybe you could 'follow' it.",
   "forest" : "The forest surrounds you.",
   "cottage" : "The cottage just sits there. Wonder why there was no back door...?",
   "grass" : "The grass grows wildy. Whoever lives in this cottage didn't take good "
	     "care of it.",
    ]));
    set_exits( ([ 
        "south"  : "/d/nopk/forest/path/room/enter2",
        "enter"  : "/d/nopk/forest/path/room/outhouse"
    ]) );
}
void reset() {
    if(!present("outhouse"))
        new("/d/nopk/forest/path/item/outhouse.c")->move(this_object());

}

