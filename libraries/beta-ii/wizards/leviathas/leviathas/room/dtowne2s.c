#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^GREEN%^A tiny forest opens up here.  Perfect tr%^ORANGE%^ee%^GREEN%^s form a path south. " );
   
    set_night_long("%^GREEN%^A tiny forest opens up here.  Perfect tr%^ORANGE%^ee%^GREEN%^s form a path south. " );
    
    set_items(([
        "trees" : "Could they have been planted to create this path?",
                  
        
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "south" : ROOMS "forest2.c",
        "north" : ROOMS "dtowne2.c",
                
                
    ]));

}


