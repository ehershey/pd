#include <std.h>
#include <roston.h>
inherit ROOM;

void create() {
  ::create();
set_name("Drow Camp");
set_items((["snow"   : "A deep white snow",
            "tent" : "A palce where members rest",
            "weapons" : "many diffent weapons layed out",
            "dirt"  : "A dark brown mixture"]));
set_properties((["light":2, "night light":3]));
set_short("camp");
set_long("This is the drow encampment, where the drows are waiting to "
        "attack roston the town to the south. There are tents layed "
     "out all around you. There are piles of weapons layed out all "
     "around.");

set_exits( ([ "east" : DROWROOM"room48",
             "west" : DROWROOM"room50" ]));
}                                                             
