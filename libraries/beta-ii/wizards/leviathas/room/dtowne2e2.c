#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("The house looks like an elephant just ran through it.  Furniture is smashed, priceless items smashed and "
           "blood is everywhere.  A staircase going upstairs has been completely destroyed, the area around where it would "
           "have been singed %^BOLD%^%^BLACK%^black%^RESET%^.  Someone strong must have had an argument with someone else here...");
   
    set_night_long("The house looks like an elephant just ran through it.  Furniture is smashed, priceless items smashed and "
           "blood is everywhere.  A staircase going upstairs has been completely destroyed, the area around where it would "
           "have been singed %^BOLD%^%^BLACK%^black%^RESET%^.  Someone strong must have had an argument with someone else here...");
    
    set_items(([
        "stairs" : "They have been completely destroyed.",
        "furniture" : "Everything has been smashed.",
        "blood" : "Could a mortal have been trespassing here?",
                  
        
        
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "east" : ROOMS "dtowne2n2.c",
                
                
    ]));

}


