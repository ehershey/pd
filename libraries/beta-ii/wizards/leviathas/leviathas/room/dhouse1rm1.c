#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("The inside of this house is nothing like the outside.  An expensive, blood-red carpet "
          "lines the floor, covering up most of the marble tiles.  The walls are made of mahogany and "
          "hold incredibly detailed paintings of mythical landscapes.  A table sits against the left wall, "
          "adjacent to a fireplace.  Stairs lead up and down. ");
   
    set_night_long("The inside of this house is nothing like the outside.  An expensive, blood-red carpet "
          "lines the floor, covering up most of the marble tiles.  The walls are made of mahogany and "
          "hold incredibly detailed paintings of mythical landscapes.  A table sits against the left wall, "
          "adjacent to a fireplace.  Stairs lead up and down. ");
    
    set_items(([
        "carpet" : "A blood-red carpet with white edging.",
        "tiles" : "They are made of perfectly cut marble, the gaps inbetween filled with silver.",
        "walls" : "Boards of mahogany have been used for the walls, nailed to the structure of the house with golden nails.",
        "stairs" : "They lead up and downstairs.",
        "fireplace" : "%^RED%^%^BOLD%^The fire crackles.%^RESET%^",
        "table" : "The chestnut-wood table is fairly plain with golden nobs.",                  
        
        
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "downstairs" : ROOMS "dhouse1rm2.c",
        "upstairs" : ROOMS "dhouse1rm3.c",
        "out" : ROOMS "dtowne3.c",
        
    ]));

}

