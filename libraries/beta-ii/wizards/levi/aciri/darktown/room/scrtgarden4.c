#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^A stone temple stands to the north.  It has a hole for a door that casts out some very dim light.  The roof of the temple is made of copper, which has rusted green.");
   
    set_night_long("%^BOLD%^A stone temple stands to the north.  It has a hole for a door that casts out some very dim light.  The roof of the temple is made of copper, which has rusted green.");
    
    set_items(([
        "temple" : "A grey, stone temple with a copper roof that has rusted green.",
                
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "south" : ROOMS "scrtgarden3.c",
        "hole" : ROOMS "library1.c",
		     
	 ]));
    
}


