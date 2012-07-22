#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("The interior of this house is nothing like it's exterior.  Banners and paintings are proudly displayed on the wall, shaking under a pale candle light.  There are no windows.  The ceiling is shaped like the underside of the roof, meaning that there is no upper floor.  There are two wooden chairs with leather backing and a simple table here.");
   
    set_night_long("The interior of this house is nothing like it's exterior.  Banners and paintings are proudly displayed on the wall, shaking under a pale candle light.  There are no windows.  The ceiling is shaped like the underside of the roof, meaning that there is no upper floor.  There are two wooden chairs with leather backing and a simple table here.");
    
    set_items(([
        "table" : "The table is plain but it serves it's purpose.",
        "chairs" : "The chairs are plain wood but they go well with the rest of the room.",
	"banners" : "The banners must belong to some rich family.",
	"paintings" : "The paintings are all of the same person, a tall and ghastly looking man.",
        
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "west" : ROOMS "dtownm2.c",
		     
	 ]));
    
}


