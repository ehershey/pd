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
        "attack roston the town to the south. There are tents layed out "
       "all around as far as you can see. The ground seems to be well "
      "traveled on. Members of the cavalry travel threw here daily.");

set_exits( ([ "south" : "/wizards/detach/roston/drow/room62",
             "north" : "/wizards/detach/roston/drow/room60", 
             "east" : "/wizards/detach/roston/drow/room63" ]));
}                                                              
void reset() {
 

  ::reset();
     if(!present("member"))
       {

new("/wizards/detach/roston/drow/mon/calvary")->move(this_object());

new("/wizards/detach/roston/drow/mon/calvary")->move(this_object());
   }
}

