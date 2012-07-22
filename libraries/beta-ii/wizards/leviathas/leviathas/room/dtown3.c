#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("A quiet and dark town");
    set_day_long("%^BOLD%^%^BLACK%^A dead end is west.  Beautiful shops enhabit "
"the north and south.  The shopkeepers don't look too nice. ");
    
    set_night_long("%^BOLD%^%^BLACK%^A dead end is west.  Beautiful shops enhabi"
"t the north and south.  The shopkeepers don't look too nice. ");

    set_items(([
          "dead end" : "It's the end of the road and it sure isn't alive.",
          "shops" : "The shops are both silver, glistening in the darkness as if "
"out of a dream.  A weapon's sign decorates the northern shop, while an armour sign
compliments the southern shop.",
          
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "wep.c",
        "south" : ROOMS "arm.c",
        "east" : ROOMS "dtown2.c",
       ]));
    add_invis_exit("");   
}
