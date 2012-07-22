#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^%^BLACK%^A rotting house stands to the north.  Everything is quiet.  Houses  go east and west. ");
   
    set_night_long("%^BOLD%^%^BLACK%^A rotting house stands to the north.  Everything is quiet.  Houses  go east and west. ");
    
    set_items(([
        "houses" : "The houses seem to stare you down.  A couple of them are missing doors that lead into black nothingness.",
        "tiles" : "The tiles have been pushed out of place or smashed from the swaying of the tower underneath.",
	                  
                
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "west" : ROOMS "dtowne3.c",
        "east" : ROOMS "dtowne5.c",
	]));
}
	




