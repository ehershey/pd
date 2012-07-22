#include <std.h>
#include <lidelas.h>

inherit ROOM;



void create()
{
    ::create();
        set_name("eni avenue");
        set_short("Eni avenue");
        set_long("Eni avenue is a street in the north end of town that runs from east to west. The streets are made of fine cobble stones, well maintained. A small alley way goes off to the south, it looks like it ends just a little farther to the south. Small lamps line this street, serving to light the street after dark. This street is rather thin, it doesn't look like many people could move about freely. Large buildings line the street, each building is several stories high. Small windows with a sharp point at the top are the common theme on all the buildings. Small carvings line the buildings, most of the carvings looks to be of gargoyles. A large forest lies to the north, it looks very thick and dark.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,]) );
        set_items(([
    	"lights"    :  "Small street lights that burn oil to light the street.",
    	"gargoyles"    :  "They are not very large, and seem to be carved into the building."
	    ]));
	    set_listen("default", "The sound of carts moving on the stone steets can be heard in all directions.");
	    set_smell("default", "The odor of horse manure fills the air.");
	    set_exits(([
			"east"		: ROOMS "lidelas021.c",
			"west"		: ROOMS "lidelas025.c",
            "south"     : ROOMS "lidelas023.c",
        ]));
}

