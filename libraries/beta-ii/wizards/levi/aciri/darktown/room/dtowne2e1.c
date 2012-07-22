#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^%^BLACK%^The inside of this house is smaller than it looked like from the outside.  A glass table holds many papers. "
            "The floor is tiled with glass and the walls tinted black windows.  A wooden staircase leads up.");
   
    set_night_long("%^BOLD%^%^BLACK%^The inside of this house is smaller than it looked like from the outside.  A glass table holds many papers. "
            "The floor is tiled with glass and the walls tinted black windows.  A wooden staircase leads up.");
    
    set_items(([
        "stairs" : "They are made of wood.",
        "glass" : "It looks very clean and well-kept.",
        "table" : "The table holds several papers.",
        "walls" : "They are black-tinted windows.",
                  
        
        
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "west" : ROOMS "dtowne2n2.c",
        "upstairs" : ROOMS "dhouse2rm2.c",
        
                
    ]));

}


