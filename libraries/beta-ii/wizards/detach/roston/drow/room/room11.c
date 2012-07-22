#include <std.h>
#include <roston.h>
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
       "all around as far as you can see. The mountains around you seem "
      "to go as high as the clouds. The wind blows swiftly threw your hair.");

set_exits( ([ "north" : DROWROOM"room12",
              "east" : DROWROOM"room65",
              "south" : DROWROOM"room10" ]));
}                                                              
void reset() {
 

  ::reset();
     if(!present("cavalry"))
       {

new(DROWMOB"calvary")->move(this_object());

new(DROWMOB"calvary")->move(this_object());
   }
}

