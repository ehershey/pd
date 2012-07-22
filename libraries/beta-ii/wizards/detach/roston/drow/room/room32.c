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
        "attack roston the town to the south. There is members of the "
        "drow army all around you, everyone excpet a few member are "
       "sleeping.");

set_exits( ([ "north" : DROWROOM"room34" ]));
}                                                    
void reset() {
 

  ::reset();
     if(!present("member"))
       {

new(DROWMOB"calvary")->move(this_object());
   }

}
