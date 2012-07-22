#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("There are few trees here.  A dim, %^MAGENTA%^purple %^RESET%^light shines from the east, from the formation. "
            "From here, it looks very unnatural.  The %^YELLOW%^stars %^RESET%^are visible from here and the sky is dark as ever. "
            "This city is an extremely odd place.");
   
    set_night_long("There are few trees here.  A dim, %^MAGENTA%^purple %^RESET%^light shines from the east, from the formation. "
            "From here, it looks very unnatural.  The %^YELLOW%^stars %^RESET%^are visible from here and the sky is dark as ever. "
            "This city is an extremely odd place.");
    
    set_items(([
        "trees" : "Could they have been planted to create this path?",
        "formation" : "It is to the east.",          
        
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "west" : ROOMS "forest3.c",
        "east" : ROOMS "formation.c",
                
                
    ]));

}


