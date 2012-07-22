#include <std.h>
#include <roston.h>
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
       "all around as far as you can see. There seems to be troops here "
 "and it looks as if there planing something.");

set_exits(([  "east" : DROWROOM"room21",
              "south" : DROWROOM"room19" ]));
}                                                              
void reset() {
 

  ::reset();
     if(!present("archer"))
       {

new(DROWMOB"archer")->move(this_object());

new(DROWMOB"archer")->move(this_object());
new(DROWMOB"calvary")->move(this_object());
new(DROWMOB"calvary")->move(this_object());   
  
  }
}

