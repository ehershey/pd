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
       "all around as far as you can see. It seems as if none of the army "
" is around this area.");

set_exits( ([ "north" : DROWROOM"room15",
             "west" : DROWROOM"room48", 
             "south" : DROWROOM"room13" ]));
}                                                             
