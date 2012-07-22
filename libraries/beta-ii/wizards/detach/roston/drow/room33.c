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
        "attack roston the town to the south. There is members of the "
        "drow army all around you, the members seem to be more awake "
         "and arnt drunk and singing.");

set_exits( ([ "east" : "/wizards/detach/roston/drow/room31",
              "west" : "/wizards/detach/roston/drow/room34" ]));
}                                                    
void reset() {
 

  ::reset();
     if(!present("member"))
       {

new("/wizards/detach/roston/drow/mon/calvary")->move(this_object());
   }

}
