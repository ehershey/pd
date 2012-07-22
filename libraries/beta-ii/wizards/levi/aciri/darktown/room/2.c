#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("A room painted with blood");
    set_day_long("%^MAGENTA%^This is the Hall of Vampires. "          
                 "Here the walls are made of some magenta coloured "
                 "wood.  Vampires can come here to rest and escape "
                 "from the world of mortals around them.");
   
    set_night_long("%^MAGENTA%^This is the Hall of Vampires. "          
                 "Here the walls are made of some magenta coloured "
                 "wood.  Vampires can come here to rest and escape "
                 "from the world of mortals around them.");
   
    
    set_items(([
	"wood" : "%^MAGENTA%^It is magenta in colour.",
	
    ]));
    set_properties(([
	"light" : 1,
	"night light" : 0,
    ]));
    set_exits(([
	"west" : ROOMS "1.c",
        
    ]));
}
