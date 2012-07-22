#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("A king sized bed stands proudly against the north wall.  the floor has the same blood-red carpet, only over "
           "a mahogany floor this time.  The walls are mahogany here too.  A couple of windows would show a nice view to the "
           "east and west, were they not boarded up from the outside. An open door leads to another room south of here.");
   
    set_night_long("A king sized bed stands proudly against the north wall.  the floor has the same blood-red carpet, only over "
           "a mahogany floor this time.  The walls are mahogany here too.  A couple of windows would show a nice view to the "
           "east and west, were they not boarded up from the outside. An open door leads to another room south of here.");
    
    set_items(([
        "carpet" : "A blood-red carpet with white edging.",
        "walls" : "Boards of mahogany have been used for the walls, nailed to the structure of the house with golden nails.",
        "stairs" : "They go downstairs.",
        "bed" : "It's decorated with expensive looking blankets and pillows.",
        "windows" : "They are boarded up from the outside.",                  
        
        
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "downstairs" : ROOMS "dhouse1rm1.c",
        "south" : ROOMS "dhouse1rm5.c",
                
    ]));

}

