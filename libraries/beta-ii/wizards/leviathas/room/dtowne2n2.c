#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^%^BLACK%^Two houses, east and west, have wide open doors.  Everyone is busy at the ball.  Everyone in this town is so rich that "
           "there exists little or no need for security of posessions.  The town looks dead from here. ");
   
    set_night_long("%^BOLD%^%^BLACK%^Two houses, east and west, have wide open doors.  Everyone is busy at the ball.  Everyone in this town is so rich that "
           "there exists little or no need for security of posessions.  The town looks dead from here. ");
    
    set_items(([
        "houses" : "Many of the houses look like they're going to collpase.  A couple, east and west, can be entered here.",
        "street" : "It's falling apart in it's old age.",
                  
        
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "dtowne2n3.c",
        "south" : ROOMS "dtowne2n.c",
        "east" : ROOMS "dtowne2e1.c",
        "west" : ROOMS "dtowne2e2.c",
        
                
    ]));

}


