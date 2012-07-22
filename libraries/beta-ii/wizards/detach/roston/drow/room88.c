#include <std.h>
inherit ROOM;

void create() {
  ::create();
set_name("Drow Camp");
set_items((["snow"   : "A deep white snow",
            "dirt"  : "A dark brown mixture"]));
set_properties((["light":2, "night light":3]));
set_short("camp");
set_long("This is the drow encampment, where the drows are waiting to "
        "attack roston, the town to the south. There are tents layed out "
       "all around as far as you can see. The drows seem to be very "
        "relaxed and calm. There seems to be a giant gold tent to "
    "the north.");

set_exits( ([ "north" : "/wizards/detach/roston/drow/room89",
              "south" : "/wizards/detach/roston/drow/room84" ]));
}                                                             
void reset() {
 

  ::reset();
     if(!present("soldier"))
       {

new("/wizards/detach/roston/drow/mon/soldier")->move(this_object());

new("/wizards/detach/roston/drow/mon/soldier")->move(this_object());
   }
}
