#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^%^BLACK%^The path to the north quickly becomes narrow and extends "
           "away northeast from the rest of the town, like a bridge going out to a slender "
	   "spire not far away.  %^BLUE%^Lightning %^BLACK%^strikes every few seconds, illuminating "
           "the dark sky for brief moments. ");
   
    set_night_long("%^BOLD%^%^BLACK%^The path to the north quickly becomes narrow and extends "
           "away northeast from the rest of the town, like a bridge going out to a slender "
	   "spire not far away.  %^BLUE%^Lightning %^BLACK%^strikes every few seconds, illuminating "
           "the dark sky for brief moments. ");
    
    set_items(([
        "path" : "The path, a slender and crumbling arm of a bridge that leads to a spire northeast of here."
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "south" : ROOMS "dtowne7.c",
	"northeast" : ROOMS "dtowndsp1.c",
		     
	 ]));
    
}


