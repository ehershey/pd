#include <std.h>
inherit ROOM;

void create() {
  ::create();
set_name("Drow Camp");
set_items((["snow"   : "A deep white snow",
            "tent" : "This tent is where members the drow army sleeps at night",
            "dirt"  : "A dark brown mixture"]));
set_properties((["light":2, "night light":3]));
set_short("camp");
set_long("This is the drow encampment, where the drows are waiting to "
        "attack roston the town to the south. There are tents layed out "
       "all around as far as you can see. There are members all around "
        "you, siting around talking and eating.");

set_exits( ([ "east" : "/wizards/detach/roston/drow/room67",
              "west" : "/wizards/detach/roston/drow/room65" ]));
}                                                              
void reset() {
 

  ::reset();
     if(!present("archer"))
       {

new("/wizards/detach/roston/drow/mon/archer")->move(this_object());

new("/wizards/detach/roston/drow/mon/archer")->move(this_object());
   }
}

