#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^GREEN%^Tr%^ORANGE%^ee%^GREEN%^s %^RESET%^continue to decorate the tiny forest.  A rock formation can be "
            "seen not far east of here.  The sky can't be seen from here, as the trees cover it.  Strange how it is somewhat "
            "brighter here.");
   
    set_night_long("%^GREEN%^Tr%^ORANGE%^ee%^GREEN%^s %^RESET%^continue to decorate the tiny forest.  A rock formation can be "
            "seen not far east of here.  The sky can't be seen from here, as the trees cover it.  Strange how it is somewhat "
            "brighter here.");
    
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
        "north" : ROOMS "dtowne2s.c",
        "east" : ROOMS "forest4.c",
                
                
    ]));

}


