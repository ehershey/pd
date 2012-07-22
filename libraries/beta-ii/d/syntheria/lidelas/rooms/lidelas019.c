#include <std.h>
#include <lidelas.h>

inherit ROOM;



void create()
{
    ::create();
        set_name("eni avenue");
        set_short("Eni avenue");
        set_long("Eni avenue is a street in the north end of town that runs from east to west. The streets are made of fine cobble stones, well maintained. This street is rather thin, it doens't look like many people could move about freely. Large buildings line the street, each building is several stories high. Small windows with a sharp point at the top are the common theme on all the buildings. Small carvings line the buildings, most of the carvings looks to be of gargoyles. A small statue of what appears to be a monk is here, it faces to the north. A large forest lies to the north, it looks very thick and dark.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,]) );
        set_items(([
    	"statue"    :  "A small statue of a monk facing north. The monk has his arm out, and in pointing to the north.",
    	"gargoyles"    :  "They are not very large, and seem to be carved into the building."
	    ]));
	    set_listen("default", "The sound of carts moving on the stone steets can be heard in all directions.");
	    set_smell("default", "The odor of horse manure fills the air.");
	    set_exits(([
			"south"		: ROOMS "lidelas018.c",
			"west"		: ROOMS "lidelas020.c",
			"north"		: ROOMS "lidelasForest001.c",
        ]));
        add_pre_exit_function("north", "go_north");
}

int go_north() {
  if(!this_player()->is_player()) return 0;
  return 1;
}


